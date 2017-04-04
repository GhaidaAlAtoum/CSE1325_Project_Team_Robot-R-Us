#include "Sales_Associate.h"
#include "PHB.h"
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
	     return 0;
  else
	     return 1;
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
	request +="Number of processed Orders : "+std::to_string(this->number_of_processed_orders());
	request +=" \n "+this->List_Of_Processed_Orders();
   PHB::add_raise_request(request);
}
/****************** Create List of Processed Orders ******************/
string SA::List_Of_Processed_Orders(){
   return("NONE");
}
/****************** Number of processed Orders ******************/
int SA::number_of_processed_orders(){
    return( Orders_processed_indexes.size());
}
/****************** Check Salary ******************/
int SA::check_Salary(){
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
	
}
/****************** Process an order ******************/
void SA::Process_an_order(){
	
}










