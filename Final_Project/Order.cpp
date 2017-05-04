#include "Sales_Associate.h"
#include "Order.h"
#include "Model.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
#include <fstream>
using namespace std;

Order::Order(int Num, Robot_model temp,string name){
	customer_name = name;
	Order_Number=Num;
	Robot_Model_Order=temp;
    time_t now =time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = * localtime(&now);
	strftime(buf,sizeof(buf),"%m/%d/%Y",&tstruct);
	Date=buf;
}
Order::Order(istream & input){
	string state=" ";
	char c=' ';
	Order_Number=get_int(input);
	state=get_string(input);
	status=read_state(state);
	Quantity=get_int(input);
	customer_name=get_string(input);
	Date = get_string(input);
	SA_who_Processed_name=get_string(input);
	c = get_char(input);
	if(c=='*'){
	 	Robot_model Robot_Model_Order(input);	 	
	}
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
Order_State Order::Get_Order_status(){
	return status;
}
/******************** Get Quantity********************/
int Order::Get_Quantity(){
	return Quantity;
}
/******************** Get Order Model Number+Name ********************/
string Order::Get_Order_Model_name(){
	string temp;
	temp +=Robot_Model_Order.Get_model_name();
	return temp;
}
string Order::Get_Order_Model_number(){
	string temp;
	temp +=Robot_Model_Order.Get_model_number();
	return temp;
}
/******************** Get SA name ********************/
string Order::Get_SAO_Name(){
	return(SA_who_Processed_name);
}
/******************** Get Customer name ********************/
string Order::Get_Customer_name(){
	return(customer_name);
   	
}
/******************** Set SA ********************/
void Order::Set_SA(string temp){
	
	SA_who_Processed_name=temp;
}
/******************** Set Status ********************/
void Order::Set_Status(Order_State i){
    status = i;
}
/******************** Set Quantity ********************/
void Order::set_Quantity(int temp){
	Quantity=temp;
}
/******************** Set Model ********************/
void Order::Set_Model(Robot_model order_model){
	Robot_Model_Order=order_model;
}
/******************** SA  sets The bill********************/
void Order::set_bill(string sent){
	bill.clear();
	bill=sent;
}
/*********** Get_Order_cost ***********/
double Order::order_price(){
   return(Robot_Model_Order.Get_model_Price());
}
double Order::order_shipping_price(){
	return(Robot_Model_Order.Get_Model_Shipping_Cost());
}
double Order::Get_Total_Price(){
  return(((this->order_price())*(8.25/100))+(this->order_shipping_price()));
	
}
/*********** Get_Order_Bill ***********/
string Order::Get_Order_Bill(){
   return(bill);	
	
}

void Order::save(ostream& output_save){
	char c ='*';
	output_save<<Order_Number<<endl;
	output_save<<print_state(status)<<endl;
	output_save<<Quantity<<endl;
	output_save<<customer_name<<endl;
	output_save<<Date<<endl;
	output_save<<SA_who_Processed_name<<endl;
	output_save<<c<<endl;
	Robot_Model_Order.save(output_save);
	
}

ostream& operator<<(ostream& out, Order& order){
  //Number Quantity	Date 	Model Name	 customer 	Status
	out<<std::left<<std::setfill(' ')<<std::setw(20)<<order.Order_Number
	              <<std::left<<std::setfill(' ')<<std::setw(15)<<order.Quantity
		          <<std::left<<std::setfill(' ')<<std::setw(20)<<order.Date
		          <<std::left<<std::setfill(' ')<<std::setw(20)<<order.Get_Order_Model_name()
		          <<std::left<<std::setfill(' ')<<std::setw(20)<<order.customer_name
		          <<std::left<<std::setfill(' ')<<std::setw(15)<<print_state(order.status)
		          <<endl;	
}





























