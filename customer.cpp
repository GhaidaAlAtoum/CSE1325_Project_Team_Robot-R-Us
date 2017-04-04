#include "customer.h"
#include "Order.h"
#include "shop.h"
#include <iostream>
#include <vector>
#include <string>


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
void customer::push_Order(Order& temp ){
	shop::add_Order(&temp);
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
/**********************************  Check Order Status **********************************/
int customer::check_order_status(int index){
   return(customer_orders[index].Get_Order_status());
}

/**********************************  Print Orders/ Bills **********************************/
string customer::view_Orders(){
	   /*
	   Order: #		Number    Date 	status		Quantitiy		Robot Model
	   */
	int i=0;
	string Order_S="#\tOrder_Number\tDate\tStatus\tQuantity\tRobot_Model\n";
	for(auto & num : customer_orders){
		Order_S += to_string(i)+"\t"+to_string(num.Get_Order_Number())+"\t"+num.Get_Order_Date()+"\t"+to_string(num.Get_Order_status())+"\t";
		Order_S += to_string(num.Get_Quantity())+"\t"+num.Get_Order_Model_Info();
	}
	return Order_S;
	}
	   
string customer::view_bills(){
	  string Order_Pill;
	  
   }


