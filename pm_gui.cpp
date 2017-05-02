#include "pm_gui.h"
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
#include "shop.h"
#include "Product_Manager.h"
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Choice.H>
Fl_Color Glob_color_l = fl_rgb_color(205, 232, 255);
using namespace std;
// MAIN window callbacks and stuff

void pm_gui::show_main() {this->show();}
void pm_gui::hide_main() {this->hide();}

void pm_gui::PM_menu_back_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_menu_back_button_cb_i();
}
void pm_gui::PM_menu_back_button_cb_i() {
    
	switch(fl_choice(" Do You Want To Exit  ?","&No","&Yes",0))
		   {
		case 1:	
	          shop::save_all();
				    cout<<"OUT\n";
				  hide_main();
				   shop::show_Menu(1,0);
	         open_p =0;
				   
			break;
		case 0: 
			break;
	}
}
void pm_gui::model_name_number(){
	name_num = new Fl_Window(300,300,"Model Name and Number");
	name_num->color(Glob_color_l);
	name_num->begin();
	AM_name = new Fl_Input(150,20,100,50,"Model Name");
	AM_number = new Fl_Input(150,80,100,50,"Model number");
	add_name_num = new Fl_Button(70,120,70,50,"ADD"); add_name_num->callback(add_new_model,this);
	name_num->end();
	name_num->show();
}
void pm_gui::add_new_model(Fl_Widget * w, void * v){
		((pm_gui*)v)->add_new_model_i();
	}
void pm_gui::add_new_model_i(){
	string n = (string) AM_name->value();
	string m = (string) AM_number->value();
	PM.Instance_new_model(n,m);
	active_name=n;
	active_num=m;
	name_num->hide();
	PM_add_model();
	
}
pm_gui::pm_gui():Fl_Window(500,500,"Project Manager"){
	
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	
	PM_add_component_button = new Fl_Button(150,150,200,50,"Add Component");
	PM_add_component_button->color(FL_WHITE);
	PM_add_component_button->labelsize(20);
	PM_add_component_button->callback(PM_add_component_button_cb, this);
	
	PM_add_model_button = new Fl_Button(150, 220, 200, 50, "Add Model");
	PM_add_model_button->color(FL_WHITE);
	PM_add_model_button->labelsize(20);
	PM_add_model_button->callback(PM_add_model_button_cb,this);
	
	PM_menu_back_button = new Fl_Button(150,400,200,50,"Back");
	PM_menu_back_button->color(FL_WHITE);
	PM_menu_back_button->labelsize(20);
	PM_menu_back_button->callback(PM_menu_back_button_cb, this);
	
	end();
	
}
void pm_gui::PM_add_model_button_cb(Fl_Widget* w, void* v){
	
	((pm_gui*)v)->PM_add_model_button_cb_i();
}
void pm_gui::PM_add_model_button_cb_i(){
	model_name_number();
}
void pm_gui::PM_add_component_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_add_component_button_cb_i();
}

// Callback makes menu for adding which type of component
void pm_gui::PM_add_component_button_cb_i() {
	
	this->hide();
	
	PM_ACM = new Fl_Window(500,500,"Add Component");
	
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	PM_ACM_addHead = new Fl_Button(150,10,200,50,"Add Head");
	PM_ACM_addHead->color(FL_WHITE);
	PM_ACM_addHead->labelsize(20);
	PM_ACM_addHead->callback(PM_ACM_addHead_cb, this);
	
	PM_ACM_addArm = new Fl_Button(150,70,200,50,"Add Arm");
	PM_ACM_addArm->color(FL_WHITE);
	PM_ACM_addArm->labelsize(20);
	PM_ACM_addArm->callback(PM_ACM_addArm_cb, this);
	
	PM_ACM_addTorso = new Fl_Button(150,130,200,50,"Add Torso");
	PM_ACM_addTorso->color(FL_WHITE);
	PM_ACM_addTorso->labelsize(20);
	PM_ACM_addTorso->callback(PM_ACM_addTorso_cb, this);
	
	PM_ACM_add_battery = new Fl_Button(150,190,200,50,"Add Battery");
	PM_ACM_add_battery->color(FL_WHITE);
	PM_ACM_add_battery->labelsize(20);
	PM_ACM_add_battery->callback(PM_ACM_addBattery_cb, this);
	
	PM_ACM_add_locomotor = new Fl_Button(150,250,200,50,"Add Locomotor");
	PM_ACM_add_locomotor->color(FL_WHITE);
	PM_ACM_add_locomotor->labelsize(20);
	PM_ACM_add_locomotor->callback(PM_ACM_addLoc_cb, this);
	
	PM_ACM_back_button = new Fl_Button(150,400,200,50,"Back");
	PM_ACM_back_button->color(FL_WHITE);
	PM_ACM_back_button->labelsize(20);
	PM_ACM_back_button->callback(PM_ACM_back_button_cb, this);
	
	PM_ACM->show();
										
}

// ALL the callbacks for component menu above

void pm_gui::PM_ACM_back_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_back_button_cb_i();	
}
void pm_gui::PM_ACM_back_button_cb_i() {
	PM_ACM->hide();
	this->show();
}

// ADD_ALL function, where components are actually created

void pm_gui::ADD_ALL_func(string component_type){

	current_component = component_type;
	
	ADD_ALL_window = new Fl_Window(500,500, "Create Component");
	
	all_inputs_box = new Fl_Box(140,20,410,285);
	all_inputs_box->color(FL_BLUE);
	
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);

	// In robot_part class..
	ADD_ALL_name_input = new Fl_Input(160, 25, 250, 30, "&Name");
	ADD_ALL_model_num_input = new Fl_Input(160, 75, 250, 30, "M&odel Number");
	ADD_ALL_cost_input = new Fl_Input(160, 125, 250, 30, "&Cost");
	ADD_ALL_description_input = new Fl_Input(160, 175, 250, 30, "&Description");
	ADD_ALL_image_input = new Fl_Input(160, 225, 250, 30, "&Image");
	ADD_ALL_weight_input = new Fl_Input(160,275,250,30,"Weight: ");
	
	
	
	// Additional Inputs based on component type..
	
	if (component_type == "head") {
		ADD_ALL_power_input = new Fl_Input(160,325,250,30,"Power");
	}
	else if (component_type == "arm") {
		ADD_ALL_max_arm_power_input = new Fl_Input(160,325,250,30,"Max Power");
	}
	else if (component_type == "battery") {
		ADD_ALL_power_available_input = new Fl_Input(160,325,250,30,"Power Available");
		ADD_ALL_max_energy_input = new Fl_Input(160,375,250,30,"Max Energy");
	}
	else if (component_type == "locomotor") {
		ADD_ALL_max_loc_power_input = new Fl_Input(160,325,250,30,"Max Power");
		ADD_ALL_max_speed_input = new Fl_Input(160,375,250,30,"Max Speed");
	}
	else if (component_type == "torso") {
		ADD_ALL_max_arms_input = new Fl_Input(160,325,250,30,"Max Arms");
		ADD_ALL_max_battery_compartments_input = new Fl_Input(160,375,250,30,"Battery Compartments");	
	}
			 
	
	ADD_ALL_create_button = new Fl_Button(70,450,100,40,"Create");
	ADD_ALL_create_button->callback(ADD_ALL_create_button_cb, this);
	ADD_ALL_create_button->color(FL_WHITE);
	ADD_ALL_cancel_button = new Fl_Button(190,450,100,40,"Cancel");
	ADD_ALL_cancel_button->color(FL_WHITE);
	ADD_ALL_cancel_button->callback(ADD_ALL_cancel_button_cb, this);
	
	ADD_ALL_window->show();
}	

// CALLBACKS for the stuff in the ADD_ALL function like back, create

void pm_gui::ADD_ALL_create_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->ADD_ALL_create_button_cb_i();	
}
void pm_gui::ADD_ALL_create_button_cb_i() {
	ADD_ALL_window->hide();
	PM_ACM->show();
	//////////////////////////////////////
	//MAKE NEW COMPONENT STUFF GOES HERE//
	//////////////////////////////////////
	cout << current_component << endl;
	// the variable current_component (above) is a string which represents
	// which kind of component is being made. Can be "head", "arm", "torso",
	// or "locomotor", or "battery". 
	/*
	// Here is how to get the info for each component being made:
	//cout << ADD_ALL_name_input->value() << endl; // name for all components
	//cout << ADD_ALL_model_num_input->value() << endl; // model num for all
	//cout << ADD_ALL_cost_input->value() << endl; // cost for all
	//cout << ADD_ALL_description_input->value() << endl; // description for all
	//cout << ADD_ALL_image_input->value() << endl; // image for all
	//cout << ADD_ALL_weight_input->value() << endl; // Weight for all 
	
	//cout << ADD_ALL_power_input->value() << endl; // Power for head
	
	//cout << ADD_ALL_max_arm_power_input->value() << endl; // Max power for arm
	
	//cout << ADD_ALL_power_available_input->value() << endl; // battery power
	//cout << ADD_ALL_max_energy_input->value() << endl; // battery max energy
	
	//cout <<	ADD_ALL_max_loc_power_input->value() << endl; // locomotor max power
	//cout << ADD_ALL_max_speed_input->value() << endl;// locomotor max speed
	
	//cout << ADD_ALL_max_arms_input->value() << endl;// torso max arms
	//cout << ADD_ALL_max_battery_compartments_input->value() << endl; //torso battery compartments	*/
	string name = (string) ADD_ALL_name_input->value();
	string model_num = (string)ADD_ALL_model_num_input->value() ;
	string cost_s = (string)  ADD_ALL_cost_input->value();
	double cost = stod(cost_s);
	string description = (string) ADD_ALL_description_input->value();
	string image = (string) ADD_ALL_image_input->value() ;
	double weight = stod((string) ADD_ALL_weight_input->value());
	
	if (current_component == "head") {
        double power = stod((string) ADD_ALL_power_input->value());
		PM.Instance_new_Head(name,model_num,description,image,cost,weight,power);
	}
	else if (current_component == "arm") {
        double power = stod((string) ADD_ALL_max_arm_power_input->value());
		PM.Instance_new_Arm(name,model_num,description,image,cost,weight,power);
	}
	else if (current_component == "battery") {
		double power =stod((string)ADD_ALL_power_available_input->value());
		double energy = stod((string)ADD_ALL_max_energy_input->value());
        PM.Instance_new_Battery(name,model_num,description,image,cost,weight,power,energy);
	}
	else if (current_component == "locomotor") {
		double speed = stod((string)ADD_ALL_max_speed_input->value()  );
		double power = stod((string) ADD_ALL_max_loc_power_input->value());
        PM.Instance_new_Locomotor(name,model_num,description,image,cost,weight,speed,power );
	}
	else if (current_component == "torso") {
		int num_arms = stoi((string) ADD_ALL_max_arms_input->value() );
		int batt_comp = stoi((string)  ADD_ALL_max_battery_compartments_input->value() );
		PM.Instance_new_Torso(name,model_num,description,image,cost,weight,num_arms,batt_comp);
	}
	
}

void pm_gui::ADD_ALL_cancel_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->ADD_ALL_cancel_button_cb_i();	
}
void pm_gui::ADD_ALL_cancel_button_cb_i() {
	PM_ACM->show();
	ADD_ALL_window->hide();
}

// CALLBACKs that call the ADD_ALL function to make the component

void pm_gui::PM_ACM_addHead_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addHead_cb_i();	
}
void pm_gui::PM_ACM_addHead_cb_i() {
	PM_ACM->hide();
	ADD_ALL_func("head");
}
void pm_gui::PM_ACM_addArm_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addArm_cb_i();	
}
void pm_gui::PM_ACM_addArm_cb_i() {
	PM_ACM->hide();
	ADD_ALL_func("arm");	
}
void pm_gui::PM_ACM_addTorso_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addTorso_cb_i();		
}
void pm_gui::PM_ACM_addTorso_cb_i() {
	ADD_ALL_func("torso");
	PM_ACM->hide();
}
void pm_gui::PM_ACM_addBattery_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addBattery_cb_i();	
}
void pm_gui::PM_ACM_addBattery_cb_i() {
	ADD_ALL_func("battery");
	PM_ACM->hide();
}
void pm_gui::PM_ACM_addLoc_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addLoc_cb_i();	
}
void pm_gui::PM_ACM_addLoc_cb_i() {
	ADD_ALL_func("locomotor");
	PM_ACM->hide();
}

// MAKE MODEL STUFF

void pm_gui::AM_ARM_CB(Fl_Widget* w, void* v) {
	((pm_gui*)v)->AM_ARM_CB_i(w,v);
}
void pm_gui::AM_ARM_CB_i(Fl_Widget* w, void* v){
	cout << "ARM CB called" << endl;
	   if(arm_counter==2){
	      fl_alert("Max Number of arms =2 ");
	   return;
                        }
   Fl_Choice * temp = (Fl_Choice*) w;
   Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
   string text= (shop::list_components(1));
	char *s= new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
		arm_counter++;
}

void pm_gui::AM_TORSO_CB(Fl_Widget* w, void* v) {
	((pm_gui*)v)->AM_TORSO_CB_i(w,v);
}
void pm_gui::AM_TORSO_CB_i(Fl_Widget * w, void * v){
   if(torso_counter==1){
	      fl_alert("Max Number of torso =1 ");
	   return;
   }
   Fl_Choice * temp = (Fl_Choice*) w;
	  Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text= (shop::list_components(2));
	char *s = new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
    torso_counter++;
}

void pm_gui::AM_LOCO_CB(Fl_Widget* w, void* v) {
	((pm_gui*)v)->AM_LOCO_CB_i(w,v);
}
void pm_gui::AM_LOCO_CB_i(Fl_Widget * w, void *v ){
	   if(loco_counter==1){
	      fl_alert("Max Number of locomotor =1 ");
	   return;
   }
   Fl_Choice * temp = (Fl_Choice*) w;
	 Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text= (shop::list_components(3));
	char *s = new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
	loco_counter++;
}

void pm_gui::AM_HEAD_CB(Fl_Widget* w, void* v) {
	((pm_gui*)v)->AM_HEAD_CB_i(w,v);
}
void pm_gui::AM_HEAD_CB_i(Fl_Widget * w, void * v){
   if(head_counter==2){
	      fl_alert("Max Number of head =1 ");
	   return;
   }
	   Fl_Choice * temp = (Fl_Choice*) w;
	 Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text= (shop::list_components(4));
char *s= new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
	head_counter++;
}

void pm_gui::AM_BATTERY_CB(Fl_Widget* w, void* v) {
	((pm_gui*)v)->AM_BATTERY_CB_i(w,v);
}
void pm_gui::AM_BATTERY_CB_i(Fl_Widget * w, void * v){

	   Fl_Choice * temp = (Fl_Choice*) w;
	 Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
   string text= (shop::list_components(5));
    char *s= new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
}

void pm_gui::AM_back_cb(Fl_Widget *w, void* v) {
	((pm_gui*)v)->AM_back_cb_i();	
}
void pm_gui::AM_back_cb_i() {
	AM_win->hide();
	this->show_main();
}

void pm_gui::ADD_Com_to_model(Fl_Widget * w, void * v){
	((pm_gui*)v)->ADD_Com_to_model_i();
}
void pm_gui::ADD_Com_to_model_i(){
	cout<<" Active Name "<<active_name<<" ACTIVE NUM "<<active_num<<endl;
	int index = (shop::get_model_index(active_name,active_num)); cout<<"Index  -->   "<<index<<endl;
	int num =stoi((string)AM_index->value());cout<<"num "<<num<<endl;
    PM.Model_Add_component(index,num);	
	shop::save_Robot_Models();
}

void pm_gui::PM_add_model() {
	
	AM_win = new Fl_Double_Window(800,500,"Input Choice");
    AM_win->begin(); 
	
	AM_win->color(Glob_color_l);
	AM_menu= new Fl_Choice(200,100,400,50,"&Shop Components");//child(0)
	AM_back = new Fl_Button(100,440,100,50,"Back");//child(1)
	AM_back->color(FL_WHITE);
	AM_back->callback(AM_back_cb, this);
	
	AM_index = new Fl_Int_Input(250,440,150,50,"Index");//child(2) 
	AM_ADD = new Fl_Button(450,440,100,50,"Add");//child(3)
	AM_ADD->color(FL_WHITE);AM_ADD->callback(ADD_Com_to_model,this);
	AM_show = new Fl_Button(600, 440,100,50,"show");//child(4)
	AM_show->color(FL_WHITE);
	AM_disp = new Fl_Text_Display(10,170,780,250, "Text");//child(5)
	AM_buff = new Fl_Text_Buffer();//child(6)
	AM_disp->buffer(AM_buff);
	AM_buff->text("Test \n Test");
	AM_menu->textfont(11); 	AM_menu->textcolor(136);
	AM_menu->add("&Arm",0,AM_ARM_CB,AM_disp);
	AM_menu->add("&Torso",0,AM_TORSO_CB,AM_disp);
	AM_menu->add("&Locomotor",0,AM_LOCO_CB,AM_disp);
	AM_menu->add("&Head",0, AM_HEAD_CB,AM_disp);
	AM_menu->add("&Battery",0,AM_BATTERY_CB,AM_disp);
    AM_win->end();
    AM_win->show();
}




















