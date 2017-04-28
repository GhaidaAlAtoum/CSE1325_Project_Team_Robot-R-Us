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
#include <FL/fl_ask.H>
#include "login.h"
#include "shop.h"
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "customer.h"
#include "PHB.h"
using namespace std;
int type_G = 0;
/****************************** lOG IN BUTTON CALLBACK ***********************************/
void unpw_login_cb(Fl_Widget* w, void* ) {
	cout <<type_G<<endl;
	Fl_Button *b =(Fl_Button*)w;
	int value=-3;
	Fl_Input  * name = (Fl_Input* ) b -> parent() -> child(2);
	Fl_Input  * pass = (Fl_Input* ) b -> parent() -> child(3);
	string username = name->value();
	string password = pass->value();
    cout <<" username "<<username<<endl<<endl;
	switch(type_G){
		case 1 :       cout<<"CHECK"<<endl;
			      value=(shop::check_PM(username,password));
			             if( value != 0){
							 cout<<" Correct"<<endl;
						//	 unpw_menu_window->hide();
							 // SHOW PM Window (Product_Manager& ( shop::login_PM()));  
						  }
			              else{
							fl_alert("Password Is Wrong");  
						  }
			               break;
		case 2 :     value=(shop::check_boss( username,password));
			              if( value != 0){
						//	  unpw_menu_window->hide();
							// SHOW PM Window (PHB & ( shop::login_boss()));  
						  }
			              else{
							fl_alert("Password Is Wrong");  
						  }
			               break;
		case 3 :       value=(shop::check_SA( username,password));
			              if(value==-1)
							  fl_alert("Password Is Wrong");
			              if (value==-2)
								 fl_alert("This SA Does Not Exist In the System ");
			              if (value != -1 && value!=-2){
							//  unpw_menu_window->hide();
							  // SHOW SA Window (SA *( shop::login(value)));
						  }
			               break;
		case 4 : value=(shop::check_customer( username,password));
			              if(value==-1)
							  fl_alert("Password Is Wrong");
			              if (value==-2)
								 fl_alert("This Customer Does Not Exist In the System ");
			              if (value != -1 && value!=-2){
							//  unpw_menu_window->hide();
							  // SHOW Customer window ( customer * (shop::login_customer(value)));
						  }
			               break;
	}
}

/****************************** CANCEL BUTTON CALLBACK ***********************************/
void unpw_cancel_cb(Fl_Widget* w, void* v) {
	//unpw_menu_window->hide();
	//shop::show_main_menu();
}
/****************************** Constructor ***********************************/
Log_In_Gui::Log_In_Gui(int Type_in )    
{   type_G=Type_in;
	unpw_menu_window = new Fl_Window(400,250,"Log In");
	Type=Type_in;
	unpw_menu_window->begin();
	/******************** Log In Button ********************/
	Fl_Button* login = new Fl_Button(100,220,40,20,"Log in");//child 0
	login->callback(unpw_login_cb, &Type);
	/******************** Cancel Button ********************/
	Fl_Button* cancel = new Fl_Button(160,220,40,20,"Cancel");//child 1
	cancel->callback(unpw_cancel_cb);
	switch(Type){
		case 1 :    //PM
			        username_input = new Fl_Input(100,20,100,20,"Name :");//child 2
	                password_input = new Fl_Input(100,50,100,20,"Password :");   //child 3    
			               break;
		case 2 :     //BOSS
			         username_input = new Fl_Input(100,20,100,20,"Name :");//child 2
	                 password_input = new Fl_Input(100,50,100,20,"Password :");//child 3
			               break;
		case 3 :     //SA
			         username_input = new Fl_Input(100,20,100,20,"Name :");//child 2
	                 password_input = new Fl_Input(100,50,100,20,"Password :");//child 3
			               break;
		case 4 :     //Customer
			         username_input = new Fl_Input(100,20,100,20,"Email :");//child 2
	                 password_input = new Fl_Input(100,50,100,20,"Password :");//child 3
			               break;
	}	
	unpw_menu_window->end();
	}

void Log_In_Gui::show_log(){
	unpw_menu_window->show();
}
void Log_In_Gui::hide_log(){
	unpw_menu_window->hide();
}














