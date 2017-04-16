#include "Controller.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

using namespace std;


////////////////////////////////////////
//////////CUSTOMER MENU STUFF//////////
/////////////////////////////////////

// The main Customer menu
void Controller::CU_menu_func() {
	
	
	hide_main_window();
	CU_menu_win = new Fl_Window(500,500,"Customer");
	
	CU_order_button = new Fl_Button(10,10,200,50,"Create Order");
	CU_order_button->callback(CU_order_button_cb, this);
	
	CU_menu_back_button = new Fl_Button(10,400,100,50,"Back");
	CU_menu_back_button->callback(CU_menu_back_button_cb, this);
	
	CU_menu_win->show();
	
}

void Controller::CU_menu_back_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->CU_menu_back_button_cb_i();	
}
void Controller::CU_menu_back_button_cb_i() {
	CU_menu_win->hide();
	show_main_window();
}


void Controller::CU_order_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->CU_order_button_cb_i();	
}
void Controller::CU_order_button_cb_i() {
	cout << "it worked" << endl;
	CU_menu_win->hide();
	CU_order_menu_func();
}

// MENU FOR CREATING ORDERS
void Controller::CU_order_menu_func() {
	CU_order_menu = new Fl_Window(500,500,"Create Order");
	
	CU_order_model = new Fl_Input(110,25,250,30,"Some option");
	CU_del_date = new Fl_Input(110,75,250,30,"Some other option");
	CU_add_comments = new Fl_Input(110,125,250,30,"Some other option");

	CU_create_order_button = new Fl_Button(10,450,70,30,"Create Order");
	CU_create_order_button->callback(CU_order_create_button_cb, this);
	CU_order_cancel_button = new Fl_Button(200,450,70,30,"Cancel");
	CU_order_cancel_button->callback(CU_order_cancel_button_cb, this);
	
	CU_order_menu->show();
	
}

void Controller::CU_order_cancel_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->CU_order_cancel_button_cb_i();	
}
void Controller::CU_order_cancel_button_cb_i() {
		CU_order_menu->hide();
		CU_menu_win->show();
}

void Controller::CU_order_create_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->CU_order_create_button_cb_i();	
}
void Controller::CU_order_create_button_cb_i() {
	
		// DO THE STUFF TO CREATE A CUSTOMER ORDER HERE!
		cout << "order created" << endl;
		CU_order_menu->hide();
		CU_menu_win->show();
}
