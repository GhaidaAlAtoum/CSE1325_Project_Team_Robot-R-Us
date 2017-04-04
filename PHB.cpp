#include "PHB.h"
#include "Sales_Associate.h"
#include "shop.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> PHB::raise_requests;
double PHB::Total_Profits=0.0;
int PHB::Total_Sales=0;
/******************* Get Instance *********************/
PHB& PHB::get_Instance_PHB(){
   static PHB instance;
	return instance;
}
/******************* Add Raise *********************/
void PHB::add_raise_request(string temp){
	raise_requests.push_back(temp);
}
/******************* Check for Raise Requests *********************/
vector<string> PHB::Check_for_raise_req(){
	vector<string> temp;
	   for(auto &num :raise_requests){
	     temp.push_back(num);
	   }
	   return temp;
   }
/******************* Add/Remove SA *********************/
void   PHB::Add_SA(string name,string pass){
    SA temp(name,pass);
	shop::add_SA(&temp);
}
void   PHB::Remove_SA(int index){
     shop::remove_SA(index);
}
/******************* Print Profit Margin for each Robot Model *********************/
string PHB::Print_Profit_Margin_Of_each_Model(){
     
}
/******************* Print Sale for each SA *********************/
string PHB::Print_sale_for_each_SA(){
	
}
/******************* Give/Deny Raide *********************/
	/* send the SA index , send 1 for YES 0 for NO */
void PHB::Give_Deny_Raise(int index, int Yes_No ) {
    shop::Give_Deny_Raise_SA(index,Yes_No);
}