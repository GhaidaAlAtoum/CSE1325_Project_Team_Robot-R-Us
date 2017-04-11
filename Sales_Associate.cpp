#include "Sales_Associate.h"
#include "PHB.h"
#include "shop.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/****************** Constructors ******************/

SA::SA() { }

SA::SA(string in_name,string in_pass){
  	SA_Name = in_name;
	SA_pass = in_pass;
 }
/****************** Check_Name_Pass ******************/
bool SA::check_SA_Name_Pass(string in_name, string in_pass){
  if(in_name == SA_Name && in_pass == SA_pass)
	     return 1;
  else
	     return 0;
}
/****************** Change Name / Pass ******************/
void SA::change_Name(string in_name){
	SA_Name = in_name;
}
void SA::change_Pass(string in_pass){
	SA_pass= in_pass;
}
/****************** Requist A Raise ******************/
void SA::Request_Raise(){
   string request;
	request +=SA_Name+"\t"+"Number of processed Orders : "+std::to_string(this->number_of_processed_orders())+"\n";
	request +="\n"+this->List_Of_Processed_Orders();
   PHB::add_raise_request(request);
}
/****************** Create List of Processed Orders ******************/
string SA::List_Of_Processed_Orders(){
   return(shop::SA_Processed_Orders(SA_Name));
}
/****************** Number of processed Orders ******************/
int SA::number_of_processed_orders(){
    return( Orders_processed_indexes.size());
}
/****************** Check Salary ******************/
double SA::check_Salary(){
	return (Month_Salary);
}
/****************** Give_Raise ******************/
void SA::Give_Raise(double Raise_by){
   Month_Salary+=Raise_by;	
}
/******************Get SA NAME ******************/
string SA::Get_SA_Name(){
   return(SA_Name);	
}
/****************** Check for Unprocessed Orders ******************/
string SA::check_for_unprocesses_Orders(){
	return(shop::Print_Unprocessed_Orders());
}
/****************** Process an order ******************/
void SA::Process_an_order(int index){
   Orders_processed_indexes.push_back(index);
   Order * temp =shop::Get_Unprocessed_Order(index);
   string pass =SA_Name;
   temp->Set_SA(pass);
	temp->Set_Status(1);
	string bill = "# Order Number  : "+to_string(temp->Get_Order_Number())+"# Date of Sale  : "+temp->Get_Order_Date()+'\n';
		   bill+= "# Customer Name : "+temp->Get_Customer_name()+'\n';
	       bill+= "# Robot Name    : "+temp->Get_Order_Model_name()+" # Robot Number : "+temp->Get_Order_Model_number()+'\n';
    shop::Process_Order(index);
}







