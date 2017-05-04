#ifndef LOGIN_H
#define LOGIN_H
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
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "customer.h"
#include "PHB.h"
using namespace std;
class Log_In_Gui
{
   public: 	
     Log_In_Gui(){}
	 Log_In_Gui(int);
	~Log_In_Gui(){}
    void show_log();
	void hide_log();
	int Type;
	Fl_Input* username_input;
	Fl_Input* password_input;
	Fl_Window* unpw_menu_window;
	
};
#endif












