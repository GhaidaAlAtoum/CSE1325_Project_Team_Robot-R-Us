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

////////////////////////////
//PM_MENU///////////////////
////////////////////////////

void Controller::PM_menu_func() {
	
	hide_main_window();
	PM_mainmenu_window = new Fl_Window(500,500,"Parts Manager");
	
	PM_add_component_button = new Fl_Button(10,10,200,50,"Add Component");
	PM_add_component_button->callback(PM_add_component_button_cb, this);
	PM_add_model_button = new Fl_Button(10, 70, 200, 50, "Add Model");
	PM_add_model_button->callback(PM_add_model_button_cb, this);
	
	PM_menu_back_button = new Fl_Button(10,400,100,50,"Back");
	PM_menu_back_button->callback(PM_menu_back_button_cb, this);
	
	
	PM_mainmenu_window->show();
	end();
	
}

void Controller::PM_menu_back_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_menu_back_button_cb_i();	
}
void Controller::PM_menu_back_button_cb_i() {
	PM_mainmenu_window->hide();
	show_main_window();
	
}


void Controller::PM_add_component_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_add_component_button_cb_i();	
}
void Controller::PM_add_component_button_cb_i() {
		PM_add_component_menu();
		PM_mainmenu_window->hide();
}

void Controller::PM_add_model_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_add_model_button_cb_i();	
}
void Controller::PM_add_model_button_cb_i() {
	PM_mainmenu_window->hide();
	add_model_func();
}