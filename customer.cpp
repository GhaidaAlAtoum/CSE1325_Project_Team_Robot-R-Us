#include "customer.h"
#include "Order.h"
#include "shop.h"
#include <iostream>
#include <vector>
#include <string>
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
void customer::cancel_order(int index){
	/* change to canceled */
	//customer_orders[index].status = 
	customer_orders.erase(customer_orders.begin()+index); 
	   
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
int customer::check_order_status(int index){
   /*return(customer_orders[index].Get_Order_status());* */
}

/**********************************  Print Orders/ Bills **********************************/
string customer::view_Orders(){
	   /*
	   Order: (#)		Number    Date 	status		Quantitiy		Model Name		Model Number
	   */
	/*int i=0;
	string Order_S="(#)\tOrder_Number\t  Date\t\tStatus\t\tQuantity\tModel Name\tModel Number\n";
	for(auto & num : customer_orders){
		Order_S +='('+to_string(i)+')'+"\t"+to_string(num.Get_Order_Number())+"\t\t"+num.Get_Order_Date()+"\t"+to_string(num.Get_Order_status())+"\t\t";
		Order_S += to_string(num.Get_Quantity())+"\t\t"+num.Get_Order_Model_name()+"\t\t"+num.Get_Order_Model_number()+"\n";
	   i++;
	}
	
	return Order_S;
	}
	   
string customer::view_bills(int index){ 
	  return(customer_orders[index].Get_Order_Bill());
*/  
}


