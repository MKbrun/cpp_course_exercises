#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      return (color == Color::WHITE) ? "white" : "black";
    }

    virtual std::string type() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    virtual char short_type() const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color) {}

    std::string type() const override {
      return color_string() + " king";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx <= 1 && dy <= 1 && (dx != 0 || dy != 0));
    }

    char short_type() const override {
      return (color == Color::WHITE) ? 'K' : 'k';
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}

    std::string type() const override {
      return color_string() + " knight";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }

    char short_type() const override {
      return (color == Color::WHITE) ? 'N' : 'n';
    }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  vector<vector<unique_ptr<Piece>>> squares;

  // Funksjonsobjekt som skal kalles etter at et sjakktrekk er gjort
  function<void()> after_piece_move;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              cout << king->color_string() << " lost the game" << endl;
          } else {
            return false;
          }
        }
        piece_to = move(piece_from);

        if (after_piece_move) {
          after_piece_move();
        }
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) : board(board) {
    board.after_piece_move = [this]() {
      print_board();
    };
  }

  void print_board() const {
    cout << "  a b c d e f g h" << endl;
    for (int y = 7; y >= 0; --y) {
      cout << y + 1 << " ";
      for (int x = 0; x < 8; ++x) {
        if (board.squares[x][y]) {
          cout << board.squares[x][y]->short_type() << " ";
        } else {
          cout << ". ";
        }
      }
      cout << y + 1 << endl;
    }
    cout << "  a b c d e f g h" << endl;
  }

private:
  ChessBoard &board;
};

int main() {
  ChessBoard board;
  ChessBoardPrint printer(board);

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  printer.print_board();
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
}
