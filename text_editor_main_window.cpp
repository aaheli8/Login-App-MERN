#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Editor.H>

class EditorWindow : public Fl_Double_Window
{
public:
    EditorWindow(int w, int h, const char *t);
    ~EditorWindow();

    Fl_Window *replace_dlg;
    Fl_Input *replace_find;
    Fl_Input *replace_with;
    Fl_Button *replace_all;
    Fl_Return_Button *replace_next;
    Fl_Button *replace_cancel;

    Fl_Text_Editor *editor;
    char search[256];
};

EditorWindow::EditorWindow(int w, int h, const char *t) : Fl_Double_Window(w, h, t)
{
    // Initialize the components of the main window
    editor = new Fl_Text_Editor(10, 10, w - 20, h - 50);
    editor->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 0);

    replace_dlg = new Fl_Window(300, 100, "Replace");
    replace_find = new Fl_Input(80, 10, 210, 25, "Find:");
    replace_with = new Fl_Input(80, 40, 210, 25, "Replace:");
    replace_all = new Fl_Button(10, 70, 80, 25, "Replace All");
    replace_next = new Fl_Return_Button(100, 70, 80, 25, "Replace Next");
    replace_cancel = new Fl_Button(190, 70, 80, 25, "Cancel");
    replace_dlg->end();

    end();
    resizable(editor);
}

EditorWindow::~EditorWindow()
{
    // Destructor to free memory
    delete editor;
    delete replace_dlg;
}

int main(int argc, char *argv[])
{
    EditorWindow *window = new EditorWindow(800, 600, "Text Editor");
    window->show(argc, argv);

    return Fl::run();
}
