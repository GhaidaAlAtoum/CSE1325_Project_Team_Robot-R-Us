#ifndef CONTROLLER_H
#define CONTROLLER_H
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
#include "shop.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include "PHB.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

bool authenticate_user(string username, string password, string person_type);

class Controller: public Fl_Window
{
	
	public:
	
	 shop SH_con=shop::Instance_shop();
	 Product_Manager PM_con= Product_Manager::get_Instance();
	 PHB  boss = PHB::get_Instance_PHB();
	Controller(); 
	void show_main_window() {this->show();}
	void hide_main_window() {this->hide();}
	string person_type;
	private:
	
	// Contained classes;

	
		
	// MAIN MENU
	Fl_Button* main_button1; // Authenticates PW for Manager, then his menu	
	Fl_Button* main_button2; // sth else
	Fl_Button* main_button3; // Custoemr
	Fl_Button* main_button4;
    

	// MAIN Menu CALLBACKS
	static void main_b1_cb(Fl_Widget*, void*);
	inline void main_b1_cb_i();
	static void main_b2_cb(Fl_Widget*, void*);
	inline void main_b2_cb_i();
	static void main_b3_cb(Fl_Widget* w, void* v);
    inline void main_b3_cb_i();
	static void main_b4_cb(Fl_Widget* w, void* v);
	inline void main_b4_cb_i();
	
	// UNPW MENU // UNPW = UserName PassWord
	
	void unpw_menu_func();
	
	static void unpw_login_cb(Fl_Widget*, void*);
	inline void unpw_login_cb_i();
	static void unpw_cancel_cb(Fl_Widget*, void*);
	inline void unpw_cancel_cb_i();
	
	const char* username;
	const char* password;
	
	Fl_Window* unpw_menu_window;
	Fl_Input* username_input;
	Fl_Input* password_input;
	
	// PM Menu Stuff
	
	void PM_menu_func();
	//void PM_menu_show();
	//void PM_menu_hide();
	Fl_Window* PM_mainmenu_window;
	Fl_Button* PM_add_component_button;
	Fl_Button* PM_add_model_button;
	Fl_Button* PM_menu_back_button;
	
	void PM_add_component_menu();
	
	// Add and Back buttons
	static void PM_add_component_button_cb(Fl_Widget*, void*);
	inline void PM_add_component_button_cb_i();	
	static void PM_add_model_button_cb(Fl_Widget*, void*);
	inline void PM_add_model_button_cb_i();
	static void PM_menu_back_button_cb(Fl_Widget*,void*);
	inline void PM_menu_back_button_cb_i();
	
	// These call the ADD_ALL_func(string) function, with the correct component as arg
	
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

	// ADD-COMPONENT MENU

	Fl_Window* PM_ACM; // ACM = ADD COMPONENT MENU
	Fl_Button* PM_ACM_addHead;
	Fl_Button* PM_ACM_addArm;
	Fl_Button* PM_ACM_addTorso;
	Fl_Button* PM_ACM_add_battery;
	Fl_Button* PM_ACM_add_locomotor;
	Fl_Button* PM_ACM_back_button;
	
	static void PM_ACM_back_button_cb(Fl_Widget* w, void* v);
	inline void PM_ACM_back_button_cb_i();
	
	// SA MENU
	void SA_menu_func();
	
	Fl_Window* SA_mainmenu_window;
	Fl_Button* SA_CRO_button; // 
	
	// ADD COMPONENT ALL WINDOW
	void ADD_ALL_func(string);
	string current_component;
	Fl_Window* ADD_ALL_window;
	
	// From Robot_Part
	Fl_Input *ADD_ALL_name_input;
	Fl_Input* ADD_ALL_cost_input;
	Fl_Input* ADD_ALL_description_input;
	Fl_Input* ADD_ALL_image_input;
	Fl_Input* ADD_ALL_weight_input;
	Fl_Input* ADD_ALL_model_num_input;
	
	// From classes of individual components
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
	
	// CUSTOMER MENU
	void CU_menu_func();
	
	Fl_Window* CU_menu_win;
	
	Fl_Button* CU_order_button;
	static void CU_order_button_cb(Fl_Widget*, void*);
	inline void CU_order_button_cb_i();
	
	Fl_Button* CU_menu_back_button;
	static void CU_menu_back_button_cb(Fl_Widget*,void*);
	inline void CU_menu_back_button_cb_i();
	
	// CU CREATE ORDER MENU
	void CU_order_menu_func();
	Fl_Window* CU_order_menu;
	Fl_Input* CU_order_model;
	Fl_Input* CU_del_date;
	Fl_Input* CU_add_comments;
	
	Fl_Button* CU_order_cancel_button;
	static void CU_order_cancel_button_cb(Fl_Widget*, void*);
	inline void CU_order_cancel_button_cb_i();
	Fl_Button* CU_create_order_button;
	static void CU_order_create_button_cb(Fl_Widget*, void*);
	inline void CU_order_create_button_cb_i();
	
	
	// BOSS main menu
	void B_menu_func();
	Fl_Window* B_menu_win;
	
	Fl_Button* BOSS_create_customer;
	Fl_Button* BOSS_create_SA;
	Fl_Button* BOSS_menu_back_b;
	
	static void BOSS_create_customer_cb(Fl_Widget*, void*);
	inline void BOSS_create_customer_cb_i();
	static void BOSS_create_SA_cb(Fl_Widget*, void*);
	inline void BOSS_create_SA_cb_i();
	static void BOSS_menu_back_b_cb(Fl_Widget*, void*);
	inline void BOSS_menu_back_b_cb_i();
	
	void BOSS_create_SA_func();
	void BOSS_create_C_func();
	
	// BOSS making SA stuff
	
	Fl_Window* create_SA_window;
	Fl_Input* new_SA_name_input;
	Fl_Input* new_SA_pass_input;
	Fl_Button* create_SA_b;
	Fl_Button* create_SA_back_b;
	
	static void create_SA_b_cb(Fl_Widget* w, void* v);
	inline void create_SA_b_cb_i();
	static void create_SA_back_b_cb(Fl_Widget*, void*);
	inline void create_SA_back_b_cb_i();
	
	// BOSS making Customer stuff
	
	Fl_Window* BOSS_create_c_win;
	Fl_Input* BOSS_CC_name_input;
	Fl_Input* BOSS_CC_phone_input;
	Fl_Input* BOSS_CC_email_input;
	Fl_Input* BOSS_CC_pass_input;
	Fl_Button* BOSS_CC_button;
	Fl_Button* BOSS_CC_cancel_button;
	
	static void BOSS_CC_button_cb(Fl_Widget*,void*);
	inline void BOSS_CC_button_cb_i();
	static void BOSS_CC_cancel_button_cb(Fl_Widget*,void*);
	inline void BOSS_CC_cancel_button_cb_i();
	
	
	// MENU to ask if returning customer or new
	void ask_if_new_func();
	
	Fl_Window* ask_if_new_win;
	Fl_Button* new_c_button;
	Fl_Button* returning_c_button;
	
	static void new_c_button_cb(Fl_Widget* w, void* v);
	inline void new_c_button_cb_i();
	static void returning_c_button_cb(Fl_Widget* w, void* v);
	inline void returning_c_button_cb_i();
	
	// CREATE USER MENU
	void create_user_func();
	Fl_Window* create_user_win;
	Fl_Input* new_user_name;
	Fl_Input* new_user_phone;
	Fl_Input* new_user_email;
	Fl_Input* new_user_password;
	
	Fl_Button* create_user_button;
	static void create_user_button_cb(Fl_Widget* w, void* v);
	inline void create_user_button_cb_i();
	
	Fl_Button* cancel_create_user_button;
	static void cancel_create_user_button_cb(Fl_Widget* w, void* v);
	inline void cancel_create_user_button_cb_i();
	
	// PM - ADD MODEL - AM
	
	void add_model_func();
	Fl_Double_Window* AM_win;
	Fl_Input* AM_name;
	Fl_Input* AM_number;
	Fl_Choice* AM_menu;
	Fl_Button* AM_back;
	Fl_Int_Input* AM_index;
	Fl_Button* AM_ADD;
	Fl_Button* AM_show;
	Fl_Text_Display* AM_disp;
	Fl_Text_Buffer* AM_buff;
	
	static void AM_back_cb(Fl_Widget*,void*);
	inline void AM_back_cb_i();
	
	
};


#endif