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


/////////////////////////////////////////
//////BOSS MENU STUFF///////////////////
///////////////////////////////////////

void Controller::B_menu_func() {
	
	hide_main_window();
	B_menu_win = new Fl_Window(500,500,"Bossy Wossy");
	
	BOSS_create_customer = new Fl_Button(20,20,200,50,"Create Customer");
	BOSS_create_customer->callback(BOSS_create_customer_cb, this);
	BOSS_create_SA = new Fl_Button(20,90,200,50,"Create Sales Associate");
	BOSS_create_SA->callback(BOSS_create_SA_cb, this);
	
	BOSS_menu_back_b = new Fl_Button(10,400,100,50,"Back");
	BOSS_menu_back_b->callback(BOSS_menu_back_b_cb, this);
	B_menu_win->show();

}

void Controller::BOSS_create_customer_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_create_customer_cb_i();	
}
void Controller::BOSS_create_customer_cb_i() {
	B_menu_win->hide();
	BOSS_create_C_func();
}

void Controller::BOSS_create_SA_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_create_SA_cb_i();	
}
void Controller::BOSS_create_SA_cb_i() {
	B_menu_win->hide();
	BOSS_create_SA_func();
}

void Controller::BOSS_menu_back_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_menu_back_b_cb_i();
}
void Controller::BOSS_menu_back_b_cb_i() {
	B_menu_win->hide();
	show_main_window();
}

// CREATE SA WINDOW

void Controller::create_SA_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->create_SA_b_cb_i();	
}
void Controller::create_SA_b_cb_i() {
	cout << "DO STUFF TO CREATE SA HERE!" << endl;	
	B_menu_win->show();
	create_SA_window->hide();
}

void Controller::create_SA_back_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->create_SA_back_b_cb_i();	
}
void Controller::create_SA_back_b_cb_i() { 
	create_SA_window->hide();
	B_menu_win->show();
}

void Controller::BOSS_create_SA_func() {
	
	create_SA_window = new Fl_Window(500,500,"Create Sales Associate");
	
	new_SA_name_input = new Fl_Input(110,25,250,30,"Name ");
	new_SA_pass_input = new Fl_Input(110,75,250,30,"Password ");
	
	create_SA_b = new Fl_Button(20,450,100,40, "Create ");
	create_SA_b->callback(create_SA_b_cb, this);
	create_SA_back_b = new Fl_Button(140,450,100,40, "Back ");
	create_SA_back_b->callback(create_SA_back_b_cb, this);
	create_SA_window->show();

}

// CREATE CUSTOMER STUFF

void Controller::BOSS_create_C_func() {

	BOSS_create_c_win = new Fl_Window(500,500,"Create Customer");
	
	BOSS_CC_name_input = new Fl_Input(110,25,250,30,"Name ");
	BOSS_CC_phone_input = new Fl_Input(110,75,250,30,"Phone ");
	BOSS_CC_email_input = new Fl_Input(110,125,250,30,"Email ");
	BOSS_CC_pass_input = new Fl_Input(110,175,250,30,"Password ");
	
	BOSS_CC_button = new Fl_Button(20,450,100,40,"Create ");
	BOSS_CC_button->callback(BOSS_CC_button_cb, this);
	BOSS_CC_cancel_button = new Fl_Button(140,450,100,40,"Cancel ");
	BOSS_CC_cancel_button->callback(BOSS_CC_cancel_button_cb, this);
	
	BOSS_create_c_win->show();
	
}

void Controller::BOSS_CC_button_cb(Fl_Widget* w,void* v) {
	((Controller*)v)->BOSS_CC_button_cb_i();	
}
void Controller::BOSS_CC_button_cb_i() {
	cout << "CREATE CUSTOMER STUFF GOES HERE!" << endl;
	BOSS_create_c_win->hide();
	B_menu_win->show();
}

void Controller::BOSS_CC_cancel_button_cb(Fl_Widget* w,void* v) {
	((Controller*)v)->BOSS_CC_cancel_button_cb_i();	
}
void Controller::BOSS_CC_cancel_button_cb_i() {
	BOSS_create_c_win->hide();
	B_menu_win->show();
}










