#ifndef PM_GUI_H
#define PM_GUI_H

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
#include <FL/Fl_Choice.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Box.H>
#include "Product_Manager.h"
using namespace std;

class pm_gui: public Fl_Window
{
    
	public:
	int open_p=1;
	int get_Open() {return open_p;}
	Product_Manager & PM = Product_Manager::get_Instance();
	
	// Some boxes so text is visible
	Fl_Box* all_inputs_box;
	
	// Pic stuff
	Fl_JPEG_Image* jpg;
	Fl_Box* main_background;
	
	// Main Window
	pm_gui();
	static void PM_add_component_button_cb(Fl_Widget*, void*);
	inline void PM_add_component_button_cb_i();	
	static void PM_add_model_button_cb(Fl_Widget*, void*);
	inline void PM_add_model_button_cb_i();
	static void PM_menu_back_button_cb(Fl_Widget*,void*);
	inline void PM_menu_back_button_cb_i();
	void show_main();
	void hide_main();
	
	// Buttons for choosing which component to add
	
	Fl_Window* PM_ACM;
	Fl_Button* PM_ACM_addHead;
	Fl_Button* PM_ACM_addArm;
	Fl_Button* PM_ACM_addTorso;
	Fl_Button* PM_ACM_add_battery;
	Fl_Button* PM_ACM_add_locomotor;
	Fl_Button* PM_ACM_back_button;
	
	static void PM_ACM_addArm_cb(Fl_Widget*,void*);
	inline void PM_ACM_addArm_cb_i();
	static void PM_ACM_addHead_cb(Fl_Widget*, void*);
	inline void PM_ACM_addHead_cb_i();
	static void PM_ACM_addLoc_cb(Fl_Widget*, void*);
	inline void PM_ACM_addLoc_cb_i();
	static void PM_ACM_addBattery_cb(Fl_Widget*, void*);
	inline void PM_ACM_addBattery_cb_i();
	static void PM_ACM_addTorso_cb(Fl_Widget*, void*);
	inline void PM_ACM_addTorso_cb_i();
	static void PM_ACM_back_button_cb(Fl_Widget*, void*);
	inline void PM_ACM_back_button_cb_i();
	
	// Menu for making component
	
	void ADD_ALL_func(string);
	
	string current_component;
	Fl_Window* ADD_ALL_window;
	
	Fl_Input *ADD_ALL_name_input;
	Fl_Input* ADD_ALL_cost_input;
	Fl_Input* ADD_ALL_description_input;
	Fl_Input* ADD_ALL_image_input;
	Fl_Input* ADD_ALL_weight_input;
	Fl_Input* ADD_ALL_model_num_input;
	
	Fl_Input* ADD_ALL_power_input;
	Fl_Input* ADD_ALL_max_arm_power_input;
	Fl_Input* ADD_ALL_power_available_input;
	Fl_Input* ADD_ALL_max_energy_input;
	Fl_Input* ADD_ALL_max_loc_power_input;
	Fl_Input* ADD_ALL_max_speed_input;
	Fl_Input* ADD_ALL_max_arms_input;
	Fl_Input* ADD_ALL_max_battery_compartments_input;
	
	Fl_Button* ADD_ALL_create_button;
	Fl_Button* ADD_ALL_cancel_button;
	
	static void ADD_ALL_create_button_cb(Fl_Widget*,void*);
	inline void ADD_ALL_create_button_cb_i();
	static void ADD_ALL_cancel_button_cb(Fl_Widget*,void*);
	inline void ADD_ALL_cancel_button_cb_i();
	
	// MAKE MODEL
	//void add_model_func();
	Fl_Double_Window* AM_win;
	Fl_Choice* AM_menu;
	Fl_Button* AM_back;
	Fl_Int_Input* AM_index;
	Fl_Button* AM_ADD;
	Fl_Button* AM_show;
	Fl_Text_Display* AM_disp;
	Fl_Text_Buffer* AM_buff;
	void PM_add_model();
	static void AM_back_cb(Fl_Widget*,void*);
	inline void AM_back_cb_i();
	static void AM_ARM_CB(Fl_Widget*,void*);
	inline void AM_ARM_CB_i(Fl_Widget*,void*);
	static void AM_TORSO_CB(Fl_Widget*,void*);
	inline void AM_TORSO_CB_i(Fl_Widget * w, void * v);
	static void AM_LOCO_CB(Fl_Widget*,void*);
	inline void AM_LOCO_CB_i(Fl_Widget * w, void * v);
	static void AM_HEAD_CB(Fl_Widget*,void*);
	inline void AM_HEAD_CB_i(Fl_Widget * w, void * v);
	static void AM_BATTERY_CB(Fl_Widget*,void*);
	inline void AM_BATTERY_CB_i(Fl_Widget * w, void * v);
	static void ADD_Com_to_model(Fl_Widget * w, void * v);
	inline void ADD_Com_to_model_i();
	int arm_counter=0;
	int torso_counter=0;
	int loco_counter=0;
	int head_counter=0;
	
	Fl_Window * name_num; 
	Fl_Input* AM_name;
	Fl_Input* AM_number;
	Fl_Button* add_name_num;
	void model_name_number();
	static void add_new_model(Fl_Widget * w, void * v);
	inline void add_new_model_i();
	string active_name ;
	string active_num;
	private:	
	
	// Main Window
	Fl_Button* PM_add_component_button;
	Fl_Button* PM_add_model_button;
	Fl_Button* PM_menu_back_button;
	
	
	//  Adding Components Stuff
	
	
};

#endif