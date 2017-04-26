#include "customer.h"
#include "Order.h"
#include "shop.h"
#include <iostream>
#include <vector>
#include <string>
#include<sstream>
#include "shop.h"

/**********************************  Constructor **********************************/
customer::customer(string name,string pass,string emailin , string phone_num){
   	Name= name;
	password=pass;
	email=emailin;
	phone_number=phone_num;
}
/**********************************  Check_Customer **********************************/
bool customer::check_customer(string name, string pass){
	 
	if(( name == Name) && (password==pass)) {
	    return 1;	
	}
	return 0;
}
/********************************** push order **********************************/
void customer::push_Order(int model_index,int Quantity ){
	customer_orders.push_back(shop::add_Order(model_index,Quantity,Name));
}
bool customer::cancel_order(int index){
   if((customer_orders[index]->Get_Order_status()) != Order_State::paid_shipped)
   {   customer_orders[index]->Set_Status(Order_State::canceled);
	   customer_orders.erase(customer_orders.begin()+index);
   return 1;
   }
	return 0;
   }
/********************************** Set Functions **********************************/
void customer::set_Name(string temp){
	   Name=temp;
}
void customer::set_email(string temp){
	temp=email;
}
void customer::set_pass(string temp){
    temp=password;
}
/********************************** Get Functions **********************************/
string customer::Get_name(){
	return Name;
}
/**********************************  Check Order Status **********************************/
string customer::check_order_status(int index){
	return(print_state(customer_orders[index]->Get_Order_status()));
}
string customer::Get_Bill_Order(int index){
	string bill;
	for(auto&num : customer_orders){
	    if(num->Get_Order_Number() == index){
			bill = num->Get_Order_Bill();
		}
	}
		return (bill);	
}
/**********************************  Print Orders/ Bills **********************************/
string customer::view_Orders(){
     std::ostringstream ss;
		ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Quantity"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Date"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Model Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Customer"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Status"<<endl;
	for(auto &num: customer_orders){
		ss << *((Order*)(num));
	}
	return (ss.str());
}
bool customer::Pay_Order(int index){
customer_orders[index]->Set_Status(Order_State::Paid);
}

