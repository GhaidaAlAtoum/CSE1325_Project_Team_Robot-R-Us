#ifndef Customer_GUI_H
#define Customer_GUI_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <vector>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <sstream>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Int_Input.H>
#include "shop.h"
#include "customer.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
using namespace std;

class Customer_gui{
  public:
	/****************************** Constructor ******************************/
	 Customer_gui(customer*,int);
	/****************************** General Functions ******************************/
	string get_hello_text();
	/****************************** Customer Gui Arguments ******************************/
	 int Quantity =-1;
	 int number_of_models=0;
	 bool open = 1;
	 bool get_open(){return open;}
	customer *temp_customer;	 
	/****************************** Main Customer Window ******************************/
	 Fl_Window* CU_menu_win;
	 Fl_Text_Display *disp;
	 Fl_Button* CU_order_button;
	 Fl_Button* CU_View_order;
	 Fl_Button* CU_change_NP;
	 Fl_Button* CU_menu_back_button;
	 void Main_CU_win();
	 void Customer_gui_show(){CU_menu_win->show();}
	 void Customer_gui_hide(){CU_menu_win->hide();}
	 /* ---------------------- Open Order Menu  callback-------------------- */
	 static void CU_order_button_cb(Fl_Widget* w, void* v);
	 inline void CU_order_button_cb_i();
	 /* ---------------------- view Customer Orders callback -------------------- */
	 static void CU_view_order_cb(Fl_Widget* w, void* v);
	 inline void CU_view_order_cb_i();
	 /* ---------------------- Change Customer Name and Password callback -------------------- */
	 static void CU_change_NP_cb(Fl_Widget* w, void* v);
	 inline void CU_change_NP_cb_i();
	 /* ----------------------  Customer Logout callback -------------------- */
	 static void CU_log_Out_cb(Fl_Widget* w, void* v);
	 inline void CU_log_Out_cb_i();
	 
	 static void window_callback(Fl_Widget* w, void*);
	 inline void window_callback_i();
	/****************************** View Models and Create an Order ******************************/
	 Fl_Window* win;
	 Fl_Button * Back;
     Fl_Scroll* scroll ;
     vector <Fl_Button*> show_pic;
	 vector <Fl_Text_Display*> Boxes;
	 vector <Fl_Button*> order_model;
	 Fl_Window * Quan;
	 Fl_Int_Input * num;
	 Fl_Button * add;
	 /* ---------------------- Creating Order Menu  -------------------- */
	void CU_order_menu_func();

    /* ---------------------- Quantity Menu -------------------- */
	  void quant_win();
      static void add_callback(Fl_Widget* w , void *v);
	  inline void    add_callback_i();
	
	/********************************** View Orders **********************************/
    void CU_View_Orders();
	 Fl_Window*  Order_win;
	 Fl_Button * Order_Back;
     Fl_Scroll*  Order_scroll ;
     vector <Fl_Button*> Pay;
	 vector <Fl_Text_Display*> Details;
	 vector <Fl_Button*> Cancel;
	 vector <Fl_Button*> View_Bill;
	
	/**************************** Change Name and Password *************************/
	 Fl_Window*  NP_win;
	 Fl_Input * string_In;
	 Fl_Button* change;
	 void change_N_P();
     int name_pass =0 ; //name
};



























#endif