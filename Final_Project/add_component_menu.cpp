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
	
////////////////////////////////////////////
/////INTERFACE FOR ADDING ALL COMPONENTS////
////////////////////////////////////////////


void Controller::ADD_ALL_func(string component_type) {
	
	current_component = component_type;
	
	ADD_ALL_window = new Fl_Window(500,500, "Create Component");
	
	// In robot_part class..
	ADD_ALL_name_input = new Fl_Input(110, 25, 250, 30, "&Name");
	ADD_ALL_model_num_input = new Fl_Input(110, 75, 250, 30, "M&odel Number");
	ADD_ALL_cost_input = new Fl_Input(110, 125, 250, 30, "&Cost");
	ADD_ALL_description_input = new Fl_Input(110, 175, 250, 30, "&Description");
	ADD_ALL_image_input = new Fl_Input(110, 225, 250, 30, "&Image");
	ADD_ALL_weight_input = new Fl_Input(110,275,250,30,"Weight: ");
	
	// Additional Inputs based on component type..
	
	if (component_type == "head") {
		ADD_ALL_power_input = new Fl_Input(110,325,250,30,"Power");
	}
	else if (component_type == "arm") {
		ADD_ALL_max_arm_power_input = new Fl_Input(110,325,250,30,"Max Power");
	}
	else if (component_type == "battery") {
		ADD_ALL_power_available_input = new Fl_Input(110,325,250,30,"Power Available");
		ADD_ALL_max_energy_input = new Fl_Input(110,375,250,30,"Max Energy");
	}
	else if (component_type == "locomotor") {
		ADD_ALL_max_loc_power_input = new Fl_Input(110,325,250,30,"Max Power");
		ADD_ALL_max_speed_input = new Fl_Input(110,375,250,30,"Max Speed");
	}
	else if (component_type == "torso") {
		ADD_ALL_max_arms_input = new Fl_Input(110,325,250,30,"Max Arms");
		ADD_ALL_max_battery_compartments_input = new Fl_Input(110,375,250,30,"Battery Compartments");	
	}
			 
	
	ADD_ALL_create_button = new Fl_Button(70,450,100,40,"Create");
	ADD_ALL_create_button->callback(ADD_ALL_create_button_cb, this);
	ADD_ALL_cancel_button = new Fl_Button(190,450,100,40,"Cancel");
	ADD_ALL_cancel_button->callback(ADD_ALL_cancel_button_cb, this);
	
	ADD_ALL_window->show();
	
}

void Controller::ADD_ALL_cancel_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->ADD_ALL_cancel_button_cb_i();		
}

void Controller::ADD_ALL_cancel_button_cb_i() {
	ADD_ALL_window->hide();
	PM_ACM->show();
}

void Controller::ADD_ALL_create_button_cb(Fl_Widget* w, void* v) {
		((Controller*)v)->ADD_ALL_create_button_cb_i();
}

void Controller::ADD_ALL_create_button_cb_i() {
	
	ADD_ALL_window->hide();
	PM_ACM->show();
	
	// Getting the information into the right format for the
	// component constructors
	
	string name = (string) ADD_ALL_name_input->value();
	string model_number = (string) ADD_ALL_model_num_input->value();
	string description = (string) ADD_ALL_description_input->value();
	string image_filename = (string) ADD_ALL_image_input->value();
	string str_cost = (string) ADD_ALL_cost_input->value();
	string str_weight = (string) ADD_ALL_weight_input->value();
	
	double cost = std::stod(str_cost);
	double weight = std::stod(str_weight);
	
	// Below, the parts are actually made. THose functions are commented out
	// Because maybe I am doing them wrong, can't test until connected
	// To rest of program
	
	// Just convert to double and int not working rn
	
	
	if (current_component == "head") {
		cout << "Head stuff added" << endl;
		
		// add head logic goes here
		string str_head_power = (string) ADD_ALL_power_input->value();
		double head_power = std::stod(str_head_power);
		
		// CREATE HEAD
		// ADD TO SHOP
	}
	else if (current_component == "arm") {
		cout << "Arm stuff added" << endl;
		
		string str_arm_power = (string) ADD_ALL_max_arm_power_input->value();
		double arm_power = std::stod(str_arm_power);
		
		// CREATE ARM
		// ADD TO SHOP
	}
	else if (current_component == "torso") {
		cout << "Torso stuff added" << endl;
		
		string str_max_arms = (string) ADD_ALL_max_arms_input->value();
		int max_arms = std::stoi(str_max_arms);
		
		string str_compartments = (string) ADD_ALL_max_battery_compartments_input->value();
		int compartments = std::stoi(str_compartments);
		
		// CREATE TORSO
		// ADD TO SHOP
	}
	else if (current_component == "battery") {
		cout << "Battery stuff added" << endl;
		
		string str_power_available = (string) ADD_ALL_power_available_input->value();
		double power_available = std::stod(str_power_available);
		
		string str_max_bat_energy = (string) ADD_ALL_max_energy_input->value();
		double max_bat_energy = std::stod(str_max_bat_energy);
		
		// CREATE BATTERY
		// ADD TO SHOP
	}
	else if (current_component == "locomotor") {
		cout << "Locomotor stuff added" << endl;
		
		string str_max_loc_power = (string) ADD_ALL_max_loc_power_input->value();
		double max_loc_power = std::stod(str_max_loc_power);
		
		string str_max_speed = (string) ADD_ALL_max_speed_input->value();
		double max_speed = std::stod(str_max_speed);
		
		// CREATE LOCOMOTOR
		// ADD TO SHOP
	}
}
