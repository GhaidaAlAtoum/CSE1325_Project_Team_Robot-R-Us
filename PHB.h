#ifndef PHB_H
#define PHB_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class PHB {
   
	 private:
	    static double Total_Profits;
	    static int Total_Sales ;
	    static vector<string> raise_requests;
	    PHB(){
		     }
	public:
	/******************* Get Instance *********************/
	 static PHB& get_Instance_PHB();
	/******************* Add Raise *********************/
	 static void add_raise_request(string);
	/******************* Check for Raise Requests *********************/
	 vector<string> Check_for_raise_req();
	/******************* Add/Remove SA *********************/
	 void   Add_SA(string,string);
	 void   Remove_SA(int);
	/******************* Print Profit Margin for each Robot Model *********************/
	 string Print_Profit_Margin_Of_each_Model();
	/******************* Print Sale for each SA *********************/
	 string Print_sale_for_each_SA();
	/******************* Give/Deny Raide *********************/
	/* send the SA index , send 1 for YES 0 for NO */
	 void Give_Deny_Raise(int,int);
	 
	
};


#endif