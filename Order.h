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
  int status=0;
  int Quantity=1;
  string Date="00/00/0000";
  SA SA_who_Processed;
  Robot_model Robot_Model_Order ;
  
  public:
	 Order(int,Robot_model);
	 /*********** Get Functions ************/
	 int Get_Order_Number();
	 int Get_Order_status();
	 int Get_Quantity();
	 string Get_Order_Date();
	 string Get_Order_Model_Info();
	 /*********** Set Functions ************/
	 void set_Quantity(int);
	 void Set_SA(SA);
	 void Set_Status(int);
	 /*********** Get_Order_cost ***********/
	 double order_price();
	 double order_shipping_price();
};

#endif