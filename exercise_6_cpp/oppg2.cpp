#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

class SimpleWebServer {
private:
  io_service io_service_;
  tcp::acceptor acceptor_;

  void handle_request(shared_ptr<tcp::socket> socket) {
    auto buffer = make_shared<boost::asio::streambuf>();

    // Les forespørselen fra klienten
    async_read_until(*socket, *buffer, "\r\n",
                     [this, socket, buffer](const boost::system::error_code &ec, size_t) {
                       if (!ec) {
                         istream request_stream(buffer.get());
                         string request;
                         getline(request_stream, request);

                         string response;

                         if (request.find("GET / HTTP/1.1") == 0) {
                           response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nDette er hovedsiden";
                         } else if (request.find("GET /en_side HTTP/1.1") == 0) {
                           response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nDette er en side";
                         } else {
                           response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found";
                         }

                         // Send respons til klienten
                         async_write(*socket, boost::asio::buffer(response),
                                     [socket](const boost::system::error_code &ec, size_t) {
                                       socket->close(); // Lukk tilkoblingen etter skriving
                                     });
                       }
                     });
  }

  void accept() {
    auto socket = make_shared<tcp::socket>(io_service_);
    acceptor_.async_accept(*socket, [this, socket](const boost::system::error_code &ec) {
      if (!ec) {
        handle_request(socket);
      }
      accept();
    });
  }

public:
  SimpleWebServer() : acceptor_(io_service_, tcp::endpoint(tcp::v4(), 8080)) {}

  void start() {
    accept();
    io_service_.run();
  }
};

int main() {
  SimpleWebServer server;
  cout << "Starting server on http://localhost:8080" << endl;
  server.start();
}
