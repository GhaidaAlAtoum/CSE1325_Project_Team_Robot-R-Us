#include "Sales_Associate.h"
#include "PHB.h"
#include "shop.h"
#include <iostream>
#include <vector>
#include <string>
#include "USE.h"
using namespace std;

/****************** Constructors ******************/

SA::SA() { }

SA::SA(string in_name,string in_pass){
  	SA_Name = in_name;
	SA_pass = in_pass;
 }
SA::SA(istream & input){
	int temp=-1;
	int i;
  	SA_Name=get_string(input);
	SA_pass=get_string(input);
	Month_Salary=get_double(input);
	temp=get_int(input);
	for(i=1;i<=temp;i++){
	  	Orders_processed_indexes.push_back(get_int(input));
	}
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
   PHB::add_raise_request(SA_Name);
}
/****************** Create List of Processed Orders ******************/
string SA::List_Of_Processed_Orders(){
   //return(shop::SA_Processed_Orders(SA_Name));
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
void SA::continue_Process_an_order(int index){
	ostringstream ss;
	Order_State temp_state;
   Orders_processed_indexes.push_back(index);
   Order * temp =shop::Get_Unprocessed_Order(index);
   Order_State check = temp->Get_Order_status();
	
   if(check == Order_State::Billed ) temp_state=Order_State::Packeged;
   else if(check == Order_State::Packeged) temp_state=Order_State::Paid;
}
void SA::Process_a_new_order(int index){
	ostringstream ss;
   Orders_processed_indexes.push_back(index);
   Order * temp =shop::Get_Unprocessed_Order(index);
   string pass =SA_Name;
    temp->Set_SA(pass);
	temp->Set_Status(Order_State::Billed);
	ss<<"\t\t\tRobot'R'Us\t\t\t"<<endl
	  <<
	string bill = "# Order Number  : "+to_string(temp->Get_Order_Number())+"# Date of Sale  : "+temp->Get_Order_Date()+'\n';
		   bill+= "# Customer Name : "+temp->Get_Customer_name()+'\n';
	       bill+= "# Robot Name    : "+temp->Get_Order_Model_name()+" # Robot Number : "+temp->Get_Order_Model_number()+'\n';
    shop::Process_Order(index);*/
}
/****************** Save And Stream ******************/
void SA::save  (ostream& output_save){
	 output_save<<SA_Name<<endl;
	 output_save<<SA_pass<<endl;
	 output_save<<Month_Salary<<endl;
	 output_save<<Orders_processed_indexes.size()<<endl;
	 for(auto& num :Orders_processed_indexes){ 
	 output_save<<num<<endl;
	 }
 }
 
ostream& operator<<(ostream& output_print, SA & sa){
	// Name Month_Salary Number of Processed Orders
	output_print<<std::left<<std::setfill(' ')<<std::setw(20)<<sa.Get_SA_Name()
	            <<std::left<<std::setfill(' ')<<std::setw(15)<<sa.Month_Salary
		        <<std::left<<std::setfill(' ')<<std::setw(25)<<(sa.Orders_processed_indexes).size()
		        <<endl;
}






