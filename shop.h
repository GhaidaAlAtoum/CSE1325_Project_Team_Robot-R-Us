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
		 shop(){
		 }
		 	      
  public:
        static shop & Instance_shop();
		/****************** ADD ********************/
		static void add_PM(Product_Manager&);
		static void add_component(Robot_Part*);
        static void add_Model(Robot_model*);
		static void add_Order(Order *);
		static void add_SA(SA*);
		/****************** REMOVE ********************/
        static void remove_component(int );
        static void remove_Model(int );
		static void remove_SA(int);
		/****************** PRINT********************/
        static string Print_Catalog_Models();
        static string Print_Catalog_Components();
		static string Print_Unprocessed_Orders() ;
        static string Print_Processed_Orders () ;
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
		static void Process_Order(int);
		/****************** PHB AND SA ******************/
		static void Give_Deny_Raise_SA(int , int);
};

#endif
