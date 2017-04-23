#ifndef PHB_H
#define PHB_H
#include "Sales_Associate.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class PHB {
   
	 private:
	    static string name;
	    static string password;
	    static vector<string> SA_req_Name;
	    PHB(){
		     }
	public:
	/******************* Get Instance *********************/
	static PHB& get_Instance_PHB();
    static void read(istream& input);
	static void set_Name_Pass(string,string);
	static bool check_PHB_Name_Pass(string,string);
	/******************* Add Raise *********************/
	static void add_raise_request(string);
	int Number_Of_raise_Req();
	/******************* Check for Raise Requests *********************/
	 string Check_for_raise_req();
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
	 void save(ostream & output_save);
     string	 Orders_by_Date(string,string);
};


#endif