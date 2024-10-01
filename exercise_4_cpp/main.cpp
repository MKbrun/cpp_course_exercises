#include <gtkmm.h>

class NameCombinerApp : public Gtk::Window {
public:
    NameCombinerApp() {
        set_title("Øving 4");

        vbox.pack_start(first_name_entry);
        vbox.pack_start(last_name_entry);
        vbox.pack_start(combine_button);
        vbox.pack_start(result_label);

        first_name_entry.set_placeholder_text("First name");
        last_name_entry.set_placeholder_text("Last name");
        combine_button.set_label("Combine names");
        combine_button.set_sensitive(false);

        first_name_entry.signal_changed().connect(sigc::mem_fun(*this, &NameCombinerApp::on_entry_changed));
        last_name_entry.signal_changed().connect(sigc::mem_fun(*this, &NameCombinerApp::on_entry_changed));
        combine_button.signal_clicked().connect(sigc::mem_fun(*this, &NameCombinerApp::on_button_clicked));

        add(vbox);
        show_all_children();
    }

protected:
    Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL};
    Gtk::Entry first_name_entry, last_name_entry;
    Gtk::Button combine_button;
    Gtk::Label result_label;

    void on_entry_changed() {
        bool both_filled = !first_name_entry.get_text().empty() && !last_name_entry.get_text().empty();
        combine_button.set_sensitive(both_filled);
    }

    void on_button_clicked() {
        result_label.set_text("Names combined: " + first_name_entry.get_text() + " " + last_name_entry.get_text());
    }
};

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    NameCombinerApp window;
    return app->run(window);
}
