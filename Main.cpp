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
	shop SH = shop::Instance_shop();
	PHB  boss = PHB::get_Instance_PHB();
	Product_Manager PM = Product_Manager::get_Instance();
    PM.change_name("Ghaida");PM.change_pass("2017");
	shop::add_PM(PM);
	SA First_SA("Rayan","Rayan123");
	shop::add_SA(&First_SA);
	First_SA.Request_Raise();
	/************************ Creating Parts *******************************/
	cout<<"\t\t\t/////////////////////\n\t\t\t// Creating Parts  //\n\t\t\t/////////////////////\n ";
	/* ~~~~~~~~~~~~~~~~~~~ ARM ~~~~~~~~~~~~~~~~~~~ */
    Arm A1("A_1","2","A_2","A_3",21,22,23);
	cout<<"Arm Max Power "<<A1.get_max_power_Arm()<<endl; cout<<"Cost Arm  "<< A1.get_cost()<<endl;
	cout<<"Shipping price  "<<A1.get_shipping_price()<<endl;cout<<"Arm Image file name  " <<A1.get_image_filename()<<endl;
    cout<<"\n ********************************** \n";
	PM.push_component(A1);
	/* ~~~~~~~~~~~~~~~~~~~ TORSO ~~~~~~~~~~~~~~~~~~~ */
	Torso T1( "T_1","1","T_2","T_3",12,13,14,15);
	Robot_Part * check = &T1;
	cout<<"Torso Battery Compartments  " <<check->get_battery_compartments()<<endl;cout<<"Torso Max arms  " <<check->get_max_arms()<<endl;
	cout<<"Cost Torso  "<< check->get_cost()<<endl;cout<<"Shipping price  "<<check->get_shipping_price()<<endl;cout<<"Torso Image file name  " <<check->get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	PM.push_component(T1);
	/* ~~~~~~~~~~~~~~~~~~~ LOCOMOTOR ~~~~~~~~~~~~~~~~~~~ */	
	Locomotor L1("L_1","3","L_2","L_3",31,32,33,34);
	cout<<"Loco max speed  "<<L1.get_max_speed()<<endl;cout<<"Loco max power  "<<L1.get_max_power()<<endl;cout<<"Cost Locomotor  "<< L1.get_cost()<<endl;
	cout<<"Shipping price  "<<L1.get_shipping_price()<<endl;cout<<"Locomotor Image file name  " <<L1.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	PM.push_component(L1);
	/* ~~~~~~~~~~~~~~~~~~~ HEAD ~~~~~~~~~~~~~~~~~~~ */
	Head H1("H_1","4","H_2","H_3",41,42,43);
	cout<<"Head power  "<<H1.Getpower()<<endl;cout<<"Cost Head  "<< H1.get_cost()<<endl;cout<<"Shipping price  "<<H1.get_shipping_price()<<endl;
	cout<<"Head Image file name  " <<H1.get_image_filename()<<endl;cout<<"\n ********************************** \n";
	PM.push_component(H1);
	/* ~~~~~~~~~~~~~~~~~~~ BATTERY ~~~~~~~~~~~~~~~~~~~ */
	Battery B1("B_1","5","B_2","B_3",51,52,53,54);
    cout<<"Battery power  "<<B1.get_power()<<endl;cout<<"Battery max energy  "<<B1.get_max_energy()<<endl;cout<<"Cost Battery  "<< B1.get_cost()<<endl;
	cout<<"Shipping price  "<<B1.get_shipping_price()<<endl;cout<<"Battery Image file name  " <<B1.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	PM.push_component(B1);
	/* ~~~~~~~~~~~~~~~~~~~ ARM 2 ~~~~~~~~~~~~~~~~~~~ */
	Arm A2("A_2","6","A_22","A_32",61,62,63.5);
	cout<<"Arm Max Power  "<<A2.get_max_power_Arm()<<endl;cout<<"Cost Arm  "<< A2.get_cost()<<endl;
	cout<<"Shipping price  "<<A2.get_shipping_price()<<endl;cout<<"Arm Image file name  " <<A2.get_image_filename()<<endl;
    cout<<"\n ********************************** \n";
	PM.push_component(A2);
	/* ~~~~~~~~~~~~~~~~~~~ BATTERY 2 ~~~~~~~~~~~~~~~~~~~ */
	Battery B2("B_2","7","B_22","B_32",71,72,73,74);
    cout<<"Battery power  "<<B2.get_power()<<endl;cout<<"Battery max energy  "<<B2.get_max_energy()<<endl;cout<<"Cost Battery  "<< B2.get_cost()<<endl;
	cout<<"Shipping price  "<<B2.get_shipping_price()<<endl;cout<<"Battery Image file name  " <<B2.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	PM.push_component(B2);
	/************************ Creating Model *******************************/
	cout<<"\t\t\t/////////////////////\n\t\t\t// Creating Model  //\n\t\t\t/////////////////////\n ";

	Robot_model mod1("MOD1.G","100CSE");
	cout<<"ADD Torsr \n";
	mod1.add_Torso(T1);
	cout<<"Can I add another Torso after I added one "<<mod1.add_Torso(T1)<<" ------> 1 YES 0 NO "<<endl;
	cout<<"ADD Head \n";
	mod1.add_Head(H1);
	cout<<"ADD Locomotor \n";
	mod1.add_Locomotor(L1);
	cout<<"ADD Battery \n";
	mod1.add_Battery(B1);
	cout<<"ADD Arm \n";
	mod1.add_Arm(A1);
	cout<<"Can I add another Arm after I added one "<<mod1.add_Arm(A2)<<" ------> 1 YES 0 NO "<<endl;
	cout<<"ADD Battery \n";
	mod1.add_Battery(B2);
	cout<<"ADD Arm \n";
	mod1.add_Arm(A2);
	cout<<"Can I add another Arm after I added two "<<mod1.add_Arm(A2)<<" ------> 1 YES 0 NO "<<endl;
	cout<<"Model Name : "<<mod1.Get_model_name()<<" Model Number : "<<mod1.Get_model_number()<<endl;
	cout<<"Model Number of Arms : "<<mod1.Get_number_of_Arms()<<endl;
	cout<<"Model Number of Batteries : "<<mod1.Get_number_of_Batteries()<<endl;
    cout<<"Model Torso # Battery Compartments : "<<mod1.Get_Torso_Bat_Comp();
	cout<<"Model Torso Max arms "<<mod1.Get_Torso_Max_arms()<<endl;
	cout<<"Model Locomotor max speed : "<<mod1.Get_Locomotor_max_speed()<<endl;
	cout<<"Model Locomotor max power : "<<mod1.Get_Locomotor_max_power()<<endl;
	cout<<"Model Head Power : "<<mod1.Get_Head_power()<<endl;
	cout<<"Model Theoritical cost : "<<mod1.Get_Model_Cost()<<endl;
	cout<<"Model Shipping Cost : "<<mod1.Get_Model_Shipping_Cost()<<endl;
	vector <double> temp = mod1.Get_Arms_power();
	int i=1;
	for(auto & num : temp){
	     	 cout<<"Arm number "<<i<< " Power : "<<num<<endl;
		i++;}
	/*************************** PHB check for Raise requests ***************************/
	vector <string> Requests = boss.Check_for_raise_req();
	for(auto & num : Requests){
	  cout<<"Requests \t"<<num<<endl;
	}
	
	/*************************** Saving Components ***************************/
	//SH.save_Robot_Components();
	
	
return 0; }











