#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "shop.h"
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include "PHB.h"
#include "login.h"
#include "mainG.h"
#include "customer_menu.h"
#include "pm_gui.h"

using namespace std;

int main(){
	/********************* Create shop *********************/
	shop SH = shop::Instance_shop();
    SH.Read_Robot_Components();
	SH.Read_Robot_Models();
	SH.Read_orders();
	SH.Read_SA_List();
	SH.Read_Customers();
    SH.Read_PM_info();
	/*cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ Catalog Components ~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<SH.Print_Catalog_Components();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ SA Read ~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<SH.Print_SA_list();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ Catalog Models ~~~~~~~~~~~~~~~~~~~~~~~~\n";	
	cout<<SH.Print_Catalog_Models();*/
	/********************* Create ProductManager *********************/
//	Product_Manager PM = Product_Manager::get_Instance();
	//PM.change_name("Ghaida");PM.change_pass("2017");
//	shop::add_PM(PM);
	/********************* Create PHB *********************/
//	PHB  boss = PHB::get_Instance_PHB();
//	shop::add_boss(boss);
	SH.show_Menu(1,0);
//	Customer_gui customer_win(5);
	 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ Catalog Models ~~~~~~~~~~~~~~~~~~~~~~~~\n";	
	cout<<SH.Print_Catalog_Models();
	
	SH.Print_Customers();	
	SH.save_orders();
	SH.save_Robot_Components();
    SH.save_Robot_Models();
	SH.save_List_SA();
	SH.save_Customers();
	SH.save_PM_info();	
return Fl::run();
}