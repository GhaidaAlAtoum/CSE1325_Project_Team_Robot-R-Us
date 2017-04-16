
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

void Controller::PM_add_component_menu() {
	PM_ACM = new Fl_Window(500,500,"Add Component");
	// ACM = ADD COMPONENT MENU
	
	PM_ACM_addHead = new Fl_Button(10,10,200,50,"Add Head");
	PM_ACM_addHead->callback(PM_ACM_addHead_cb, this);
	
	PM_ACM_addArm = new Fl_Button(10,70,200,50,"Add Arm");
	PM_ACM_addArm->callback(PM_ACM_addArm_cb, this);
	
	PM_ACM_addTorso = new Fl_Button(10,130,200,50,"Add Torso");
	PM_ACM_addTorso->callback(PM_ACM_addTorso_cb, this);
	
	PM_ACM_add_battery = new Fl_Button(10,190,200,50,"Add Battery");
	PM_ACM_add_battery->callback(PM_ACM_addBattery_cb, this);
	
	PM_ACM_add_locomotor = new Fl_Button(10,250,200,50,"Add Locomotor");
	PM_ACM_add_locomotor->callback(PM_ACM_addLoc_cb, this);
	
	PM_ACM_back_button = new Fl_Button(10,400,100,50,"Back");
	PM_ACM_back_button->callback(PM_ACM_back_button_cb, this);
	
	PM_ACM->show();
										 
	
}

void Controller::PM_ACM_back_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_back_button_cb_i();	
}
void Controller::PM_ACM_back_button_cb_i() {
	PM_ACM->hide();
	PM_menu_func();

}

// CALLBACKs that call the ADD_ALL function to make the component

void Controller::PM_ACM_addHead_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_addHead_cb_i();	
}
void Controller::PM_ACM_addHead_cb_i() {
	ADD_ALL_func("head");		
	PM_ACM->hide();
}

void Controller::PM_ACM_addArm_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_addArm_cb_i();	
}
void Controller::PM_ACM_addArm_cb_i() {
	PM_ACM->hide();
	ADD_ALL_func("arm");	
}

void Controller::PM_ACM_addTorso_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_addTorso_cb_i();	
}
void Controller::PM_ACM_addTorso_cb_i() {
	ADD_ALL_func("torso");
	PM_ACM->hide();
}

void Controller::PM_ACM_addBattery_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_addTorso_cb_i();
}
void Controller::PM_ACM_addBattery_cb_i() {
	ADD_ALL_func("battery");
	PM_ACM->hide();
}

void Controller::PM_ACM_addLoc_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_addLoc_cb_i();
}
void Controller::PM_ACM_addLoc_cb_i() {
	ADD_ALL_func("locomotor");
	PM_ACM->hide();
}

