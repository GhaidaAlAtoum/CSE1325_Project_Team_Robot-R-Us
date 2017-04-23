#include "PHB.h"
#include "Sales_Associate.h"
#include "shop.h"
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <sstream>
using namespace std;
vector<string> PHB::SA_req_Name;
string PHB::name="DEFAULT";
string PHB::password="123";
/******************* Get Instance *********************/
PHB& PHB::get_Instance_PHB(){
   static PHB instance;
	return instance;
}
void PHB::read(istream& input){
	int i =0;
	int j=1;
	name=get_string(input);
	password=get_string(input);
	i=get_int(input);
	 for(;j<=i;j++){
	   PHB::add_raise_request(get_string(input));
	 }
}
void PHB::set_Name_Pass(string n, string p){
   name =n; 
   password=p;
}
bool PHB::check_PHB_Name_Pass(string in_name, string in_pass){
  if(in_name == name && in_pass == password)
	     return 1;
  else
	     return 0;
}
/******************* Add Raise *********************/
void PHB::add_raise_request(string temp){
	SA_req_Name.push_back(temp);
}
/******************* Check for Raise Requests *********************/
string PHB::Check_for_raise_req(){
	string temp;
	std::ostringstream ss;
	ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Month Salary"
		<<std::left<<std::setfill(' ')<<std::setw(25)<<"Number of Orders processed"<<endl;
		for(auto& num: SA_req_Name){
			temp+=shop::PRINT_SA_BY_NAME(num);
		}
	 return(ss.str()+temp);

   }
int PHB::Number_Of_raise_Req(){
   return(SA_req_Name.size());
}
/******************* Add/Remove SA *********************/
void   PHB::Add_SA(string name,string pass){
    SA *temp = new SA(name,pass);
	shop::add_SA(temp);
}
void   PHB::Remove_SA(int index){
     shop::remove_SA(index);
}
/******************* Print Profit Margin for each Robot Model *********************/
string PHB::Print_Profit_Margin_Of_each_Model(){
     return(shop::Print_Profit_Margin());
}
/******************* Print Sale for each SA *********************/
string PHB::Print_sale_for_each_SA(){
	return(shop::Print_SA_list());
}
/******************* Give/Deny Raide *********************/
	/* send the SA index , send 1 for YES 0 for NO */
void PHB::Give_Deny_Raise(int index, int Yes_No ) {
    shop::Give_Deny_Raise_SA(index,Yes_No);
	SA_req_Name.erase(SA_req_Name.begin() + index);
}

void PHB::save(ostream & output_save){
       output_save<<name<<endl;
	   output_save<<password<<endl;
	   output_save<<Number_Of_raise_Req()<<endl;
	   for(auto& num : SA_req_Name){
		   output_save<<num<<endl;
	   }
}

string PHB::Orders_by_Date(string from, string To){
	
	
}













