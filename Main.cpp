#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "shop.h"
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include "PHB.h"


using namespace std;

int main(){
	/********************* Create shop *********************/
	shop SH = shop::Instance_shop();
    SH.Read_Robot_Components();
	SH.Read_Robot_Models();
	SH.Read_orders();
	SH.Read_SA_List();
	
	SH.Read_Customers();
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ Catalog Components ~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<SH.Print_Catalog_Components();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ SA Read ~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<SH.Print_SA_list();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ Catalog Models ~~~~~~~~~~~~~~~~~~~~~~~~\n";	
	cout<<SH.Print_Catalog_Models();
	/********************* Create ProductManager *********************/
	Product_Manager PM = Product_Manager::get_Instance();
	PM.change_name("Ghaida");PM.change_pass("2017");
	shop::add_PM(PM);
	/********************* Create PHB *********************/
	PHB  boss = PHB::get_Instance_PHB();
	shop::add_boss(boss);
	/********************* PHB Create SA *********************/
//	boss.Add_SA("Chris","Chris123");
	/********************* Create a Customer *********************/
	customer Num1("John","123","John@gmail.com","684-987-8654");
    customer Num2("Jake","546","Jake@outlook.com","654-892-4721");
	shop::add_Customer(&Num1);
		shop::add_Customer(&Num2);
	
//	cout<<" Is Customer True "<<Num1.check_customer("John","123")<<endl;
    /********************* PM adding Components *********************/
/*    PM.Instance_new_Arm("A_1","2","A_2","A_3",21,22,23); //0
	PM.Instance_new_Torso("T_1","1","T_2","T_3",12,13,14,15); //1
	PM.Instance_new_Locomotor("L_1","3","L_2","L_3",31,32,33,34); //2
	PM.Instance_new_Head("H_1","4","H_2","H_3",41,42,43); //3
	PM.Instance_new_Battery("B_1","5","B_2","B_3",51,52,53,54);//4
	PM.Instance_new_Arm("A_2","6","A_22","A_32",61,62,63.5);//5
	PM.Instance_new_Battery("B_2","7","B_22","B_32",71,72,73,74);//6*/
	/********************* PM adding Model *********************/
/* 	PM.Instance_new_model("Model11","100122");
	PM.Model_Add_component(0,0); //arm (1)
	PM.Model_Add_component(0,1);//torso (1)
	PM.Model_Add_component(0,2);//loco (1)
	PM.Model_Add_component(0,3);//head (1)
	PM.Model_Add_component(0,4);//batt (1)
	PM.Model_Add_component(0,1);//torso (2) -- Should cout<< " Can ADD TORSO : 0" 
	PM.Model_Add_component(0,5);//arm (2) 
	PM.Model_Add_component(0,5);//arm (3) -- Should cout<< " Can ADD ARM : 0"
	PM.Instance_new_model("Model22M","8672");
	PM.Model_Add_component(1,1);//torso (1)
	PM.Model_Add_component(1,3);//head (1)
	PM.Model_Add_component(1,5);//arm (2)*/
	/********************* Customer Making an Order *********************/
  /*   cout<<"Customer "<<Num1.Get_name()<< " "<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ ############## ~~~~~~~~~~~~~~~~~~~~~~~~\n";	*/
/*	cout<<Num1.view_Orders()<<endl;
 Num1.push_Order(1,5);
Num1.push_Order(0,10);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ ############## ~~~~~~~~~~~~~~~~~~~~~~~~\n";	
cout<<Num1.view_Orders()<<endl;*/
/*	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~##############~~~~~~~~~~~~~~~~~~~~~~~~\n";	
	cout<<Num1.check_order_status(0)<<endl;
    cout<<(Num1.Get_Bill_Order(0))<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~##############~~~~~~~~~~~~~~~~~~~~~~~~\n";*/
    /********************* Process an Order *********************/
  /*SA * Test;
    int T=shop::check_SA("Rayan","Rayan123");
	if(T==-1){
	   cout<<"Wrong PASS \n";	 
	 }
	else if(T==-2){
		cout<<"SA does not exist"<<endl;
	}
	else{
		cout<<"Log In success\n";
	    Test=shop::login(T);
	
	cout<<"~~~~~~~~~~~~~~ Unprocessed_Ordrs ~~~~~~~~~~~~~~~~~\n";
	cout<< (Test->check_for_unprocesses_Orders()) <<endl;
		cout<<endl<<endl;
	Test->Process_a_new_order(0);
		
		cout<<endl<<endl;
	}
	cout<<Num1.Get_Bill_Order(0)<<endl;
	//Num1.cancel_order(0);
	cout<<"~~~~~~~~~~~~~~ processed_Ordrs ~~~~~~~~~~~~~~~~~\n";
    cout<<shop::Print_all_Orders()<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ ############## ~~~~~~~~~~~~~~~~~~~~~~~~\n";	
	cout<<Num1.view_Orders()<<endl;
    cout<<"~~~~~~~~~~~~~~ Unprocessed_Ordrs ~~~~~~~~~~~~~~~~~\n";
	cout<<shop::Print_Unprocessed_Orders()<<endl;
	Num1.Pay_Order(0);
    cout <<" ################ continue_Process_an_order ############### \n";
	cout<<shop::Print_Orders_By_SA(Test->Get_SA_Name());
	Test->continue_Process_an_order(0);
	cout<<"~~~~~~~~~~~~~~ processed_Ordrs ~~~~~~~~~~~~~~~~~\n";
    cout<<shop::Print_all_Orders()<<endl;
	    cout <<" ################ continue_Process_an_order ############### \n";
	cout<<shop::Print_Orders_By_SA(Test->Get_SA_Name());
	Test->continue_Process_an_order(0);
	cout<<"~~~~~~~~~~~~~~ processed_Ordrs ~~~~~~~~~~~~~~~~~\n";
    cout<<shop::Print_all_Orders()<<endl;
	cout<<" Cancel = "<<Num1.cancel_order(0)<<endl;
	cout<<"~~~~~~~~~~~~~~ processed_Ordrs ~~~~~~~~~~~~~~~~~\n";
    cout<<shop::Print_all_Orders()<<endl;
	/********************* Request A raise *********************/
/*	Test->Request_Raise();
	boss.Give_Deny_Raise(0,1);
	cout<<Test->Get_SA_Name()<<" SALARY "<<Test->check_Salary()<<endl;
	/********************* PM Removing Model *********************/
	//PM.pull_component(5);
	/********************* PM Removing Model *********************/
	//PM.pull_Model(0);
	/*************************** PHB check for Raise requests ***************************/
/*	cout<<"~~~~~~~~~~~~ List of SA ~~~~~~~~~~~~\n"; 
	cout<<boss.Print_sale_for_each_SA()<<endl;
	cout<<"\n";
	vector <string> Requests = boss.Check_for_raise_req();
	for(auto & num : Requests){
	  cout<<"Requests \t"<<num<<endl;
	}
   	cout<<"\n\n";
	cout<<PM.Print_Catalog_Components(5)<<endl; */
	/*************************** Saving Components ***************************/
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~ Catalog Components ~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<PM.Print_Catalog_Components(5)<<endl;
	cout<<PM.Print_Catalog_model()<<endl;
	SH.save_orders();
	SH.save_Robot_Components();
    SH.save_Robot_Models();
	SH.save_List_SA();
	SH.save_Customers();
return 0; }











