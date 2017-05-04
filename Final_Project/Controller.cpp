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
#include "Controller.h"
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

// This is a test class to make sure that I can access shop and stuff from within the gui stuff.
// Test-Run with: g++ -std=c++11 gui_beginnings.cpp -lfltk -o gui_beginnings.out

// MAIN

int main()
	
{ 
   	Controller controller;	
	controller.PM_con.change_name("CSE");controller.PM_con.change_pass("2017");
	shop::add_PM(controller.PM_con);
	/********************* PM adding Components *********************/
    controller.PM_con.Instance_new_Arm("A_1","2","A_2","A_3",21,22,23); //0
	controller.PM_con.Instance_new_Torso("T_1","1","T_2","T_3",12,13,14,15); //1
	controller.PM_con.Instance_new_Locomotor("L_1","3","L_2","L_3",31,32,33,34); //2
	controller.PM_con.Instance_new_Head("H_1","4","H_2","H_3",41,42,43); //3
	controller.PM_con.Instance_new_Battery("B_1","5","B_2","B_3",51,52,53,54);//4
	controller.PM_con.Instance_new_Arm("A_2","6","A_22","A_32",61,62,63.5);//5
	controller.PM_con.Instance_new_Battery("B_2","7","B_22","B_32",71,72,73,74);//6
	
	controller.show();
	
	return(Fl::run());
	
}