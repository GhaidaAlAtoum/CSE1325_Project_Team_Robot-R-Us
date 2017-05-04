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
	     vector <Order*> customer_orders;
	  public:
	     customer(string,string,string,string);
	customer(istream & input);
/**********************************  Check_Customer **********************************/
   bool  check_customer(string,string);
/**********************************  Print Orders/ Bills **********************************/
   string  view_Orders(int);
   string  view_bills(int index);
/********************************** push order **********************************/
   void  push_Order(int,int);
/********************************** Set Functions **********************************/
   void  set_Name(string);
   void  set_email(string);
   void  set_pass(string);
	int Get_Number_of_orders();
/********************************** Get Functions **********************************/
   string Get_name();
   string Get_email();
   string Get_Bill_Order(int index);
/**********************************  Check Order Status **********************************/
   string  check_order_status(int);
   bool cancel_order(int index);
	bool Pay_Order(int index);
	void save(ostream & output_save);
};

#endif