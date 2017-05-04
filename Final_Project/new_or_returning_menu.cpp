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

/////////////////////////////////////////  ///
//NEW OR RETURNING CUSTOMER MENU////////  ///
///////////////////////////////////////  ///



// The window for creating a new user

void Controller::create_user_func() {

	create_user_win = new Fl_Window(500,500,"Create New User");
	
	new_user_name = new Fl_Input(110,25,250,30,"Name ");
	new_user_phone = new Fl_Input(110,75,250,30,"Phone ");
	new_user_email = new Fl_Input(110,125,250,30,"Email ");
	new_user_password = new Fl_Input(110,175,250,30,"Password ");
	
	create_user_button = new Fl_Button(10,450,70,40,"Create User");
	create_user_button->callback(create_user_button_cb, this);
	cancel_create_user_button = new Fl_Button(200,450,70,40,"Cancel");
	cancel_create_user_button->callback(cancel_create_user_button_cb, this);
											  
	create_user_win->show();
	
}

void Controller::create_user_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->create_user_button_cb_i();	
}
void Controller::create_user_button_cb_i() {
	
	// STUFF TO MAKE NEW USER GOES HERE!!
	cout << "New Customer Created!" << endl;
		
	create_user_win->hide();
}

void Controller::cancel_create_user_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->cancel_create_user_button_cb_i();	
}
void Controller::cancel_create_user_button_cb_i() {
	create_user_win->hide();
}






// Asks if someone is a new or returning user

void Controller::ask_if_new_func() {
	
	ask_if_new_win = new Fl_Window(200,200,"Returning Customer?");
	
	returning_c_button = new Fl_Button(10,150,70,40,"Returning");
	returning_c_button->callback(returning_c_button_cb, this);
	
	new_c_button = new Fl_Button(100,150,70,40,"New");
	new_c_button->callback(new_c_button_cb, this);
	
	ask_if_new_win->show();
	
}

void Controller::returning_c_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->returning_c_button_cb_i();	
}
void Controller::returning_c_button_cb_i() {
	ask_if_new_win->hide();
	unpw_menu_func();
}

void Controller::new_c_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->new_c_button_cb_i();	
}
void Controller::new_c_button_cb_i() {
	ask_if_new_win->hide();
	create_user_func();
}

