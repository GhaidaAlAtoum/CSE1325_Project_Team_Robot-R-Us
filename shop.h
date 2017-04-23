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

using namespace std;

class shop
{
  private:
         static vector <Robot_Part*> components;
		 static vector <Robot_model*> Models;
		 static vector <customer> shop_Customers;
		 static Product_Manager shop_Product_Manager;
		 static vector <Order*> shop_processed_Orders ; 
         static vector <Order*>  shop_unprocessed_Orders ;
         static vector <SA*> Sales_Associate_of_Shop;
		 static int num_orders ;
		 shop(){
		 }
		 	      
  public:
        static shop & Instance_shop();
		/****************** ADD ********************/
		static void add_PM(Product_Manager&);
		static void add_component(Robot_Part*);
        static void add_Model(Robot_model*);
		static Order add_Order(int,int,string);
		static void add_SA(SA*);
		static void model_add_component(int ,int );
		/****************** REMOVE ********************/
        static void remove_component(int );
        static void remove_Model(int );
		static void remove_SA(int);
		/****************** PRINT********************/
        static void Print_Catalog_Models();
        static void Print_Catalog_Components();
		static string Print_Unprocessed_Orders() ;
        static string Print_Processed_Orders () ;
		static void Print_SA_list();
        /****************** SAVE ********************/
		static void save_List_SA();
        static void save_PHB_info();
        static void save_PM_info();
		static void save_Robot_Models();
		static void save_Robot_Components();
		/****************** READ ********************/
        static void Read_Robot_Components();
        static void Read_Robot_Models();
	    static void Read_SA_List();
		static void Read_PHB_info();
		static void Read_PM_info();
		/****************** Process Order ******************/
		static void   Process_Order(int);
		static Order* Get_Unprocessed_Order(int); 
		/****************** PHB AND SA ******************/
		static void Give_Deny_Raise_SA(int , int);
		
		static int get_num_orders(){ return num_orders; }
		/****************** Destructor *****************/
		~shop();
		/****************** Log in of Customers and SA ******************/
		static SA* login(int);
        static int check_SA(string,string);
        static string SA_Processed_Orders(string);
		static string List_Of_SA();
		static string list_components(int);
};

#endif
