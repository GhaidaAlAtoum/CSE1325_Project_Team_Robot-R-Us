#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Order.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class customer {
      private:
	     string Name="customer";
	     string password="customer";
	     string email="customer@----.com";
	     string phone_number="***-***-****";
	     vector <Order> customer_orders;
	  public:
	     customer(string,string,string,string);
/**********************************  Check_Customer **********************************/
   bool  check_customer(string,string);
/**********************************  Print Orders/ Bills **********************************/
   string  view_Orders();
   string  view_bills();
/********************************** push order **********************************/
   void  push_Order(Order&);
/********************************** Set Functions **********************************/
   void  set_Name(string);
   void  set_email(string);
   void  set_pass(string);
/**********************************  Check Order Status **********************************/
   int  check_order_status(int);
 
};

#endif