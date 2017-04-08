#include "shop.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include "PHB.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
	/********************* Create shop *********************/
	shop SH = shop::Instance_shop();
	/********************* Create ProductManager *********************/
	Product_Manager PM = Product_Manager::get_Instance();
	PM.change_name("Ghaida");PM.change_pass("2017");
	shop::add_PM(PM);
	/********************* Create PHB *********************/
	PHB  boss = PHB::get_Instance_PHB();
	/********************* PHB Create SA *********************/
    boss.Add_SA("Rayan","Rayan123");
	boss.Add_SA("Chris","Chris123");
	/********************* Create a Customer *********************/
	customer Num1("John","123","John@gmail.com","684-987-8654");
	cout<<" Is Customer True "<<Num1.check_customer("John","123")<<endl;
    /********************* PM adding Components *********************/
    PM.Instance_new_Arm("A_1","2","A_2","A_3",21,22,23); //0
	PM.Instance_new_Torso("T_1","1","T_2","T_3",12,13,14,15); //1
	PM.Instance_new_Locomotor("L_1","3","L_2","L_3",31,32,33,34); //2
	PM.Instance_new_Head("H_1","4","H_2","H_3",41,42,43); //3
	PM.Instance_new_Battery("B_1","5","B_2","B_3",51,52,53,54);//4
	PM.Instance_new_Arm("A_2","6","A_22","A_32",61,62,63.5);//5
	PM.Instance_new_Battery("B_2","7","B_22","B_32",71,72,73,74);//6
	/********************* PM adding Model *********************/
	PM.Instance_new_model("Model11","100122");
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
	PM.Model_Add_component(1,5);//arm (2)
	/********************* Customer Making an Order *********************/
     Num1.push_Order(1,5);
	/********************* PM Removing Model *********************/
	PM.pull_component(5);
	/********************* PM Removing Model *********************/
	PM.pull_Model(0);
	/*************************** PHB check for Raise requests ***************************/
	vector <string> Requests = boss.Check_for_raise_req();
	for(auto & num : Requests){
	  cout<<"Requests \t"<<num<<endl;
	}
   	
	/*************************** Saving Components ***************************/
	SH.save_Robot_Components();
	SH.save_Robot_Models();
	
return 0; }











