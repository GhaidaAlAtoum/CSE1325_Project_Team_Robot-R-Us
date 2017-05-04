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

/////////////////////////////
////SA MENU//////////////////
/////////////////////////////

void Controller::SA_menu_func() {

	hide_main_window();

	SA_mainmenu_window = new Fl_Window(500,500, "Sales Associate Menu");
	
	SA_CRO_button = new Fl_Button(10,10,200,50, "Create a robot order");
	
	
	SA_mainmenu_window->show();
}

