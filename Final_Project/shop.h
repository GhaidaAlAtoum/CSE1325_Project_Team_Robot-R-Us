#ifndef SHOP_H
#define SHOP_H
#include "Order.h"
#include "Sales_Associate.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "USE.h"
#include "login.h"
#include "mainG.h"
using namespace std;

class shop
{
  private:
         /****************** components ********************/
         static vector <Robot_Part*> components;
		 /****************** Models ********************/
		 static vector <Robot_model*> Models;
		 /****************** Customers ********************/
		 static vector <customer*> shop_Customers;
		 /****************** Product Manager &  Boss ********************/
		 static Product_Manager shop_Product_Manager;
		 static PHB boss;
		 /****************** Orders ********************/
         static vector <Order*>  shop_orders ;
		 static int num_orders ;
		 /****************** Sales Associates ********************/
         static vector <SA*> Sales_Associate_of_Shop;
	
		 shop(){}
		 	      
  public:
        //////////////////////////// GUI FUNCTIONS ////////////////////////////
		static void show_Menu(int Type,int);
       /****************** Shop Get Instance  ********************/
        static shop & Instance_shop();
		/****************** ADD ********************/
		static void add_PM(Product_Manager&);
		static void add_boss(PHB & temp);
		static void add_Customer(customer * temp);
		static void add_component(Robot_Part*);
        static void add_Model(Robot_model*);
		static Order* add_Order(int,int,string);
		static void add_SA(SA*);
		static void model_add_component(int ,int );
		/****************** REMOVE ********************/
        static void remove_component(int );
        static void remove_Model(int );
		static void remove_SA(int);
		static void remove_order(int);
		static void save_orders();
		static void save_Customers();
		/****************** PRINT********************/
        static string Print_Catalog_Models();
		static string Print_Customers();
        static string Print_Catalog_Components();
		static string Print_all_Orders() ;
        static string Print_Unprocessed_Orders () ;
		static string Print_SA_list();
		static string Print_Profit_Margin();
		static string Print_Orders_By_SA(string name);
		static string Print_Models_by_index(int index);
        /****************** SAVE ********************/
		static void save_List_SA();
        static void save_PHB_info();
        static void save_PM_info();
		static void save_Robot_Models();
		static void save_Robot_Components();
		static void save_all();
		/****************** READ ********************/
        static void Read_Robot_Components();
        static void Read_Robot_Models();
	    static void Read_SA_List();
		static void Read_PHB_info();
		static void Read_PM_info();
		static void Read_orders();
		static void Read_Customers();
		/****************** Process Order ******************/
		static void   Process_Order(int,Order_State);
		static Order* Get_Unprocessed_Order(int); 
		/****************** PHB AND SA ******************/
		static void Give_Deny_Raise_SA(int , int);
		static int get_num_orders(){ return num_orders; }
		/****************** Destructor *****************/
		~shop();
		/****************** Log in of Customers, SA, PM, BOSS  ******************/
		static bool check_PM(string , string );
		static Product_Manager& login_PM();
		static int check_boss(string, string);
		static PHB& login_boss();
        static int check_SA(string,string);
		static SA* login(int);
		static int check_customer(string, string);
		static customer* login_customer(int);
		/***************** Print SA bu name ********************/
        static string PRINT_SA_BY_NAME(string);
		/***************** print componentss by type ********************/
		static string list_components(int);
		static int get_model_index(string name, string num);
};

#endif
