#ifndef ORDER_H
#define ORDER_H
#include "Sales_Associate.h"
#include "Model.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
class Order
{
  private:
  int Order_Number=0;
  Order_State status=Order_State::pending;
  int Quantity=1;
  string bill = "Notrocessed Yet";
  string customer_name=" ";
  string Date="00/00/0000";
  string SA_who_Processed_name="Def";
  Robot_model Robot_Model_Order ;
  
  public:
	 Order(int,Robot_model,string);
	 Order(istream&);
	 /*********** Get Functions ************/
	 int Get_Order_Number();
	 Order_State Get_Order_status();
	 int Get_Quantity();
	 string Get_Order_Date();
	 string Get_Order_Model_name();
	 string Get_Order_Model_number();
	 string Get_SAO_Name();
	 string Get_Customer_name();
	 /*********** Set Functions ************/
	 void set_Quantity(int);
	 void Set_SA(string);
	 void Set_Status(Order_State);
	 void Set_Model(Robot_model);
	 /*********** SA  sets The bill ***********/
	 void set_bill(string);
	 /*********** Get_Order_cost ***********/
	 double order_price();
	 double order_shipping_price();
	 /*********** Get_Order_Bill ***********/
	 string Get_Order_Bill();
	 void save(ostream&);
	 friend ostream& operator<<(ostream&,Order&);
};

#endif