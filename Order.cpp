#include "Sales_Associate.h"
#include "Order.h"
#include "Model.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

Order::Order(int Num, Robot_model temp){
	Order_Number=Num;
	Robot_Model_Order=temp;
    time_t now =time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = * localtime(&now);
	strftime(buf,sizeof(buf),"%m/%d/%Y",&tstruct);
	Date=buf;
}
/******************** Get Order Number ********************/
int Order::Get_Order_Number(){
 return Order_Number;
}
/******************** Get Order Date ********************/
string Order::Get_Order_Date(){
	return Date;
}
/******************** Get Order Status ********************/
int Order::Get_Order_status(){
	return status;
}
/******************** Get Quantity********************/
int Order::Get_Quantity(){
	return Quantity;
}
/******************** Get Order Model Number+Name ********************/
string Order::Get_Order_Model_Info(){
	string temp=NULL;
	/* Model Number Model Name */
	temp +=Robot_Model_Order.Get_model_number()+"\t"+Robot_Model_Order.Get_model_name();
	return temp;
}
/******************** Set SA ********************/
void Order::Set_SA(SA temp){
	SA_who_Processed=temp;
}
/******************** Set Status ********************/
void Order::Set_Status(int i){
    status = i;
}
/******************** Set Quantity ********************/
void Order::set_Quantity(int temp){
	Quantity=temp;
}
/*********** Get_Order_cost ***********/
double Order::order_price(){
   return(Robot_Model_Order.Get_Model_Cost());
}
double Order::order_shipping_price(){
	return(Robot_Model_Order.Get_Model_Shipping_Cost());
}














