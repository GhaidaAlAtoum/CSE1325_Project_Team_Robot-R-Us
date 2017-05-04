#ifndef MAIN_GUI_H
#define MAIN_GUI_H
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
using namespace std;

class main_menu {
		public:
		Fl_Window* main_window;
		Fl_Button* main_button1;
		Fl_Button* main_button2;
		Fl_Button* main_button3;
		Fl_Button* main_button4;
		Fl_Box *main_background;
     	Fl_JPEG_Image * jpg;
	    Fl_Box *Title_box;
        Fl_JPEG_Image *jpg2;
		main_menu();
		void show_window();
		void hide_window();
};



#endif
