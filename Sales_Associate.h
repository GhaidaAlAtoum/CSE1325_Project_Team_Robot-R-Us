#ifndef SALES_H
#define SALES_H
#include "PHB.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SA 
{
    private:
	    string SA_Name="Default";
		string SA_pass="123456";
		vector<int> Orders_processed_indexes;
		double Month_Salary = 1000.0;
	public:
	    /****************** Constructors ******************/
	    SA();
		SA(string,string);
		SA(istream& input);
		/****************** Check_Name_Pass ******************/
		bool check_SA_Name_Pass(string,string);
		/****************** Change Name / Pass ******************/
		void change_Name(string);
		void change_Pass(string);
		/****************** Requist A Raise ******************/
		void Request_Raise();
		/****************** Check for Unprocessed Orders ******************/
		string check_for_unprocesses_Orders();
		string check_for_cts_Orders();
		/****************** Process an order ******************/
		void continue_Process_an_order(int index);
		void Process_a_new_order(int);
		/****************** Create List of Processed Orders ******************/
		string List_Of_Processed_Orders();
		/******************Get SA NAME ******************/
		string Get_SA_Name();
		/****************** Number of processed Orders ******************/
		int number_of_processed_orders();
		/****************** Check Salary ******************/
        double check_Salary();
		/****************** Give_Raise ******************/
		void Give_Raise(double); 
        /****************** Save And Stream ******************/
        void save  (ostream& output_save);
        friend ostream& operator<<(ostream& output_print, SA & sa);


};


#endif 