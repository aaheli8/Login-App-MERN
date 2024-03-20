#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_File_Chooser.H>

Fl_Text_Buffer *textBuffer = new Fl_Text_Buffer();

void open_cb(Fl_Widget *, void *);
void save_cb(Fl_Widget *, void *);
void cut_cb(Fl_Widget *, void *);
void copy_cb(Fl_Widget *, void *);
void paste_cb(Fl_Widget *, void *);
void find_cb(Fl_Widget *, void *);
void replace_cb(Fl_Widget *, void *);

class EditorWindow : public Fl_Double_Window
{
public:
    EditorWindow(int w, int h, const char *t);
    ~EditorWindow();

    Fl_Text_Editor *editor;
    Fl_Menu_Bar *menu_bar;
};

EditorWindow::EditorWindow(int w, int h, const char *t) : Fl_Double_Window(w, h, t)
{
    menu_bar = new Fl_Menu_Bar(0, 0, w, 30);
    editor = new Fl_Text_Editor(0, 30, w, h - 30);
    editor->buffer(textBuffer);

    menu_bar->add("File/Open", FL_CTRL + 'o', open_cb, this);
    menu_bar->add("File/Save", FL_CTRL + 's', save_cb, this);
    menu_bar->add("Edit/Cut", FL_CTRL + 'x', cut_cb, this);
    menu_bar->add("Edit/Copy", FL_CTRL + 'c', copy_cb, this);
    menu_bar->add("Edit/Paste", FL_CTRL + 'v', paste_cb, this);
    menu_bar->add("Search/Find", FL_CTRL + 'f', find_cb, this);
    menu_bar->add("Search/Replace", FL_CTRL + 'r', replace_cb, this);

    end();
    resizable(editor);
}

EditorWindow::~EditorWindow()
{
    delete editor;
    delete menu_bar;
}

void open_cb(Fl_Widget *, void *data)
{
    EditorWindow *window = (EditorWindow *)data;
    const char *file = fl_file_chooser("Open File", "*", NULL);
    if (file != NULL)
    {
        textBuffer->loadfile(file);
        window->redraw();
    }
}

void save_cb(Fl_Widget *, void *data)
{
    EditorWindow *window = (EditorWindow *)data;
    const char *file = fl_file_chooser("Save File", "*", NULL);
    if (file != NULL)
    {
        textBuffer->savefile(file);
        window->redraw();
    }
}

void cut_cb(Fl_Widget *, void *)
{
    Fl_Text_Editor::kf_cut(0, 0);
}

void copy_cb(Fl_Widget *, void *)
{
    Fl_Text_Editor::kf_copy(0, 0);
}

void paste_cb(Fl_Widget *, void *)
{
    Fl_Text_Editor::kf_paste(0, 0);
}

void find_cb(Fl_Widget *, void *)
{
    fl_alert("Working on it!!!");
}

void replace_cb(Fl_Widget *, void *)
{
    fl_alert("Working on it!!!");
}

int main(int argc, char *argv[])
{
    EditorWindow *window = new EditorWindow(800, 600, "Text Editor");
    window->show(argc, argv);

    return Fl::run();
}
