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
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "sa_gui.h"
#include "shop.h"

using namespace std;

/////////////////////////////
////SA MENU//////////////////
/////////////////////////////

void sa_gui::SA_menu_back_cb(Fl_Widget* w, void* v) {
	((sa_gui*)v)->SA_menu_back_cb_i();
}
void sa_gui::SA_menu_back_cb_i() {
		switch(fl_choice(" Do You Want To Exit  ?","&No","&Yes",0))
		   {
		case 1:	
	          shop::save_all();
				  SA_mainmenu_window->hide();
				   shop::show_Menu(1,0);
	         open_sa =0;
				   
			break;
		case 0: 
			break;
	}
}

sa_gui::sa_gui(SA * sent ) {
     temp = sent;
	SA_mainmenu_window = new Fl_Window(500,500, "Sales Associate Menu");
	SA_mainmenu_window->begin();
	
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	SA_process_order = new Fl_Button(150,150,200,50, "Continue Process Order");
	SA_process_order->color(FL_WHITE);
	SA_process_order->labelsize(20);
	SA_process_order->callback(SA_process_order_cb, this);
	
	SA_menu_back = new Fl_Button(150,400,200,50, "Back");
	SA_menu_back->color(FL_WHITE);
	SA_menu_back->labelsize(20);
	SA_menu_back->callback(SA_menu_back_cb, this);
	
	SA_CRO_button = new Fl_Button(150,220,200,50, "Process New Order");
	SA_CRO_button->labelsize(20);
	SA_CRO_button->color(FL_WHITE);
	SA_mainmenu_window->end();
	SA_CRO_button->callback(SA_APPROVE_ORDER_CB, this);
}

// APPROVE ORDER STUFF

void sa_gui::SA_APPROVE_ORDER_CB(Fl_Widget* w, void* v){
	((sa_gui*)v)->SA_APPROVE_ORDER_CB_i();
}
void sa_gui::SA_APPROVE_ORDER_CB_i() {
	SA_mainmenu_window->hide();
	SA_process_order_win = new Fl_Window(500,500,"Choose orders");
	
	SA_process_order_win->begin();
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	process_order_back = new Fl_Button(30,425,200,50,"Back");
	process_order_back->callback(process_order_back_cb, this);
	process_order_back->color(FL_WHITE);
	
	order_list = new Fl_Multiline_Output(0,0,500,400);
	get_index = new Fl_Int_Input(280,430,70,40,"Index");
	
	process_order_enter = new Fl_Button(390,405,70,40,"Enter");
	process_order_enter->callback(approve_order_enter_cb, this);
	process_order_enter->color(FL_WHITE);
	
	process_order_info = new Fl_Button(390,455,70,40,"Info");
	process_order_info->callback(approve_order_info_cb, this);
	process_order_info->color(FL_WHITE);
	
	string orders = (temp->check_for_unprocesses_Orders());
	const char* out_orders = orders.c_str();
	order_list->value(out_orders);
	SA_process_order_win->resizable(order_list);
	
	SA_process_order_win->show();
	
}

void sa_gui::approve_order_enter_cb(Fl_Widget* w, void* v) {
	((sa_gui*)v)->approve_order_enter_cb_i();	
}
void sa_gui::approve_order_enter_cb_i() {
	SA_process_order_win->hide();
	SA_mainmenu_window->show();
	const char* index = get_index->value();
	cout << index << endl;
	
		//////////////////////////
		///GHAIDA/////////////////
		///GHAIDA/////////////////
		//////////////////////////
		//Here, you can use the var "index" 
		// To know which order should be Approved
		// and put the code here
}

void sa_gui::approve_order_info_cb(Fl_Widget* w, void* v) {
	((sa_gui*)v)->approve_order_info_cb_i();	
}
void sa_gui::approve_order_info_cb_i() {
	order_info_func(atoi(get_index->value()));
}

void sa_gui::SA_process_order_cb(Fl_Widget* w, void* v) {
	((sa_gui*)v)->SA_process_order_cb_i();	
}
void sa_gui::SA_process_order_cb_i() {
	SA_process_order_func();
	SA_mainmenu_window->hide();
}

// PROCESS ORDER STUFF

void sa_gui::SA_process_order_func() {

	SA_process_order_win = new Fl_Window(500,500,"Choose orders");
	
	SA_process_order_win->begin();
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	process_order_back = new Fl_Button(30,425,200,50,"Back");
	process_order_back->callback(process_order_back_cb, this);
	process_order_back->color(FL_WHITE);
	
	order_list = new Fl_Multiline_Output(0,0,500,400);
	get_index = new Fl_Int_Input(280,430,70,40,"Index");
	
	process_order_enter = new Fl_Button(390,405,70,40,"Enter");
	process_order_enter->callback(process_order_enter_cb, this);
	process_order_enter->color(FL_WHITE);
	
	process_order_info = new Fl_Button(390,455,70,40,"Info");
	process_order_info->callback(process_order_info_cb, this);
	process_order_info->color(FL_WHITE);

	string orders =temp->check_for_cts_Orders();
	const char* out_orders = orders.c_str();
	order_list->value(out_orders);
	
	
		SA_process_order_win->resizable(order_list);
	SA_process_order_win->show();
	
}

void sa_gui::process_order_info_cb(Fl_Widget* w,void* v) {
	((sa_gui*)v)->process_order_info_cb_i();
}
void sa_gui::process_order_info_cb_i() {
	order_info_func(atoi(get_index->value()));
}

void sa_gui::process_order_back_cb(Fl_Widget* w,void* v) {
	((sa_gui*)v)->process_order_back_cb_i();
}
void sa_gui::process_order_back_cb_i() {
	SA_process_order_win->hide();
	SA_mainmenu_window->show();
}

void sa_gui::process_order_enter_cb(Fl_Widget* w, void* v) {
	((sa_gui*)v)->process_order_enter_cb_i();	
}
void sa_gui::process_order_enter_cb_i() {
	SA_process_order_win->hide();
	SA_mainmenu_window->show();
	const char* index = get_index->value();
	cout << index << endl;
	
		//////////////////////////
		///GHAIDA/////////////////
		///GHAIDA/////////////////
		//////////////////////////
		//Here, you can use the var "index" 
		// To know which order should be processed
		// and put the code here
}


// The window to display 
void sa_gui::order_info_func(int in_index) {
	
		SA_order_info_win = new Fl_Window(400,200,"Order Info");
	
		//////////////////////////
		///GHAIDA/////////////////
		///GHAIDA/////////////////
		//////////////////////////
		// This is where info about an order is printed
		// so that the sa knows what is going on.
		// just the index of the order is necessary
		// It can be accessed with "in_index" variable as shown below
		cout << "The index was: " << in_index << endl;
		
		// You can put a string to display the info into a box 
		// using the code below
		string temp_info = "This will have some information about the order \nBut in the meantime it says you are cool";
		const char* temp_info_2 = temp_info.c_str();
		order_info_box = new Fl_Multiline_Output(0,0,400,200);
		order_info_box->value(temp_info_2);
	
		
	
		SA_order_info_win->show();
}

void sa_gui::show_window() {SA_mainmenu_window->show();}
void sa_gui::hide_window() {SA_mainmenu_window->hide();}

/*
int main() {
	
	sa_gui* sa = new sa_gui();
	sa->show_window();
	
	return(Fl::run());
}
*/