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


bool authenticate_user(string username, string password, string person_type) {
	// Here goes the stuff for checking the username and password
	cout << person_type << endl;
	return true;
}

/////////////////////////////////////////
// Password menu functions, callbacks //
///////////////////////////////////////

void Controller::unpw_menu_func() {
	
	unpw_menu_window = new Fl_Window(400,250,"Authenticate User");
	
	username_input = new Fl_Input(100,20,100,20,"Username:");
	password_input = new Fl_Input(100,50,100,20,"Password:");
	
	
	Fl_Button* login = new Fl_Button(100,220,40,20,"Log in");
	login->callback(unpw_login_cb, this);
	Fl_Button* cancel = new Fl_Button(160,220,40,20,"Cancel");
	cancel->callback(unpw_cancel_cb, this);
	
	
	end();
	unpw_menu_window->show();
}
	
	
void Controller::unpw_login_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->unpw_login_cb_i();
}
void Controller::unpw_login_cb_i() {
	
	const char* temp_username = username_input->value();
	std::string username(temp_username);
	const char* temp_password = password_input->value();
	std::string password(temp_password);
	
	bool user_accepted = authenticate_user(username, password, person_type);
	if (user_accepted) {
		
		unpw_menu_window->hide();
		if (person_type == "PM")
			PM_menu_func();
		else if (person_type == "SA")
			SA_menu_func();
		else if (person_type == "CU")
			CU_menu_func();
		else if (person_type == "B")
			B_menu_func();
		
	}
}


void Controller::unpw_cancel_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->unpw_cancel_cb_i();	
}
void Controller::unpw_cancel_cb_i() {
	unpw_menu_window->hide();
}

