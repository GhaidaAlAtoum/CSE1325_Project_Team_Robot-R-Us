#ifndef SA_GUI_H
#define SA_GUI_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Int_Input.H>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Choice.H>

using namespace std;

class sa_gui 
{public:
    SA * temp ; 
	Fl_JPEG_Image* jpg;
	Fl_Box* main_background;
	int open_sa =1;
    int get_Open() {return open_sa;}
	// SA MENU
	Fl_Window* SA_mainmenu_window;
	Fl_Button* SA_CRO_button; 
	Fl_Button* SA_menu_back;
	
	static void SA_process_order_cb(Fl_Widget*,void*);
	inline void SA_process_order_cb_i();
	static void SA_menu_back_cb(Fl_Widget*, void*);
    inline void SA_menu_back_cb_i();

	
	
	
	// SA process customer order - Choosing the order
	
	void SA_process_order_func();
	Fl_Window* SA_process_order_win;
	Fl_Button* process_order_back;
	Fl_Multiline_Output* order_list;
	Fl_Int_Input* get_index;
	Fl_Button* process_order_enter;
	Fl_Button* SA_process_order;
	Fl_Button* process_order_info;
	
	
	static void process_order_info_cb(Fl_Widget*, void*);
	inline void process_order_info_cb_i();
	static void process_order_back_cb(Fl_Widget*,void*);
	inline void process_order_back_cb_i();
	static void process_order_enter_cb(Fl_Widget*, void*);
	inline void process_order_enter_cb_i();
	
	
	// APPROVE ORDER
	static void SA_APPROVE_ORDER_CB(Fl_Widget*, void*);
    inline void SA_APPROVE_ORDER_CB_i();
	
	static void approve_order_enter_cb(Fl_Widget*, void*);
	inline void approve_order_enter_cb_i();
	static void approve_order_info_cb(Fl_Widget*, void*);
	inline void approve_order_info_cb_i();

	
	// SA order info window
	void order_info_func(int);
	Fl_Window* SA_order_info_win;
	Fl_Multiline_Output* order_info_box;
	
	
	void show_window();
	void hide_window();
	sa_gui(SA*);
};

#endif