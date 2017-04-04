#include "shop.h"
#include "Sales_Associate.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include<cstdio>


using namespace std;
vector <Robot_Part*> shop::components;
vector <Robot_model*> shop::Models;
vector <customer> shop::shop_Customers;
Product_Manager shop::shop_Product_Manager = Product_Manager::get_Instance();
vector <Order*> shop::shop_processed_Orders ; 
vector <Order*>  shop::shop_unprocessed_Orders ;
vector <SA*> shop::Sales_Associate_of_Shop;
shop& shop::Instance_shop( )
{
	static shop instance;
           return instance;
}
/****************** ADD ********************/
void shop::add_PM(Product_Manager & temp){
 shop_Product_Manager=temp;	
}
void shop::add_component(Robot_Part * temp){
    	components.push_back(temp);
}
void shop::add_Model(Robot_model* temp){
    	Models.push_back(temp);
}
void shop::add_Order(Order *temp){
     shop_unprocessed_Orders.push_back(temp);
}
void shop::add_SA(SA * temp){
     shop::Sales_Associate_of_Shop.push_back(temp);
}
/****************** REMOVE ********************/
void shop::remove_component(int index){
	    components.erase(components.begin() + index);
}
void shop::remove_Model(int index){
	Models.erase(Models.begin() + index);
}
void shop::remove_SA(int index){
	    Sales_Associate_of_Shop.erase(Sales_Associate_of_Shop.begin()+index);
}
/****************** PRINT********************/
string shop::Print_Catalog_Models(){
	
}
string shop::Print_Catalog_Components(){
	
}
string shop::Print_Unprocessed_Orders(){}
string shop::Print_Processed_Orders (){}
/****************** SAVE ********************/
void shop::save_Robot_Models(){
	char c='*';
	ofstream ShopFile ("Robot_Models_Saved.txt");
	for( auto & num : Models ){
	  ShopFile<<c<<endl;
	   
	}
	
	ShopFile.close();
}
void shop::save_Robot_Components(){
	ofstream shopFile ("Robot_Components_Saved.txt");
	for( auto & num : components ){
	    switch(num->Type()){
			case 1: shopFile<<num->Type()<<endl;
				    shopFile<<num->get_part_name()<<endl;
				    shopFile<<num->get_part_number()<<endl;
				    shopFile<<num->get_part_description()<<endl;
				    shopFile<<num->get_image_filename()<<endl;
				    shopFile<<num->get_cost()<<endl;
				    shopFile<<num->get_weight()<<endl;
				    shopFile<<num->get_max_power_Arm()<<endl;
				    break;
			case 2: shopFile<<num->Type()<<endl;
				    shopFile<<num->get_part_name()<<endl;
				    shopFile<<num->get_part_number()<<endl;
				    shopFile<<num->get_part_description()<<endl;
				    shopFile<<num->get_image_filename()<<endl;
				    shopFile<<num->get_cost()<<endl;
				    shopFile<<num->get_weight()<<endl;
				    shopFile<<num->get_max_arms()<<endl;
				    shopFile<<num->get_battery_compartments()<<endl;
				
				    break;
			case 3: shopFile<<num->Type()<<endl;
				    shopFile<<num->get_part_name()<<endl;
				    shopFile<<num->get_part_number()<<endl;
				    shopFile<<num->get_part_description()<<endl;
				    shopFile<<num->get_image_filename()<<endl;
				    shopFile<<num->get_cost()<<endl;
				    shopFile<<num->get_weight()<<endl;
				    shopFile<<num->get_max_speed()<<endl;
				    shopFile<<num->get_max_power()<<endl;
				
			        break;
			case 4: shopFile<<num->Type()<<endl;
				    shopFile<<num->get_part_name()<<endl;
				    shopFile<<num->get_part_number()<<endl;
				    shopFile<<num->get_part_description()<<endl;
				    shopFile<<num->get_image_filename()<<endl;
				    shopFile<<num->get_cost()<<endl;
				    shopFile<<num->get_weight()<<endl;
				    shopFile<<num->Getpower()<<endl;
				
				    break;
			case 5: shopFile<<num->Type()<<endl;
				    shopFile<<num->get_part_name()<<endl;
				    shopFile<<num->get_part_number()<<endl;
				    shopFile<<num->get_part_description()<<endl;
				    shopFile<<num->get_image_filename()<<endl;
				    shopFile<<num->get_cost()<<endl;
				    shopFile<<num->get_weight()<<endl;
				    shopFile<<num->get_power()<<endl;
				    shopFile<<num->get_max_energy()<<endl;
				
				    break;				
				
		}		
		 
	 } 
	
	shopFile.close();
}
void shop::save_List_SA(){
	
}
void shop::save_PHB_info(){
	
}
void shop::save_PM_info(){
	
}
/****************** READ ********************/
void shop::Read_Robot_Components(){
	Arm A;
	Torso T;
	Locomotor L;
	Head H;
	Battery B;
	string line , name , description, image,model_num;
	int n=-1,i=0;
	int type, Torso_max_arms,Torso_batt_com;
	double cost, weight, arm_power, loco_speed,loco_power,head_power,batt_power,batt_energy;
	ifstream shopFile1("Components.txt");
	if(shopFile1.is_open()){
		while(!shopFile1.eof()){
			getline(shopFile1,line);
			n++;}
		shopFile1.close();
	}
	ifstream file2("Components.txt");
	if(file2.is_open()){
		while((!file2.eof()) && i<n){
			getline(file2,line);
			std::stringstream(line)>>type;
			switch(type) {
				case 1: 
					    getline(file2,line); name=line;A.Set_part_name(name);
					    getline(file2,line);model_num=line;A.set_part_model_num(model_num);
					    getline(file2,line);description=line;A.Set_part_description(description);
					    getline(file2,line);image=line;A.Set_part_image(image);
					    getline(file2,line);stringstream(line)>>cost;A.Set_part_cost(cost);
					    getline(file2,line);stringstream(line)>>weight;A.Set_part_weight(weight);
						getline(file2,line);stringstream(line)>>arm_power;A.set_arm_power(arm_power);
					    shop::add_component(&A);
					    i+=8;
					    break;
				case 2:  
					    getline(file2,line); name=line;T.Set_part_name(name);
					    getline(file2,line);model_num=line;T.set_part_model_num(model_num);
					    getline(file2,line); description=line;T.Set_part_description(description);
					    getline(file2,line);image=line;T.Set_part_image(image);
					    getline(file2,line);stringstream(line)>>cost;T.Set_part_cost(cost);
					    getline(file2,line);stringstream(line)>>weight;T.Set_part_weight(weight);
					    getline(file2,line);stringstream(line)>>Torso_max_arms;T.set_Torso_max_arms(Torso_max_arms);
					    getline(file2,line);stringstream(line)>>Torso_batt_com;	T.set_Torso_batt(Torso_batt_com);
					    shop::add_component(&T);
					    i+=8;
					    break;
				case 3: 
					    getline(file2,line);name=line;L.Set_part_name(name);
					    getline(file2,line);model_num=line;L.set_part_model_num(model_num);
					    getline(file2,line);description=line;L.Set_part_description(description);
					    getline(file2,line);image=line;L.Set_part_image(image);
					    getline(file2,line);stringstream(line)>>cost;L.Set_part_cost(cost);
					    getline(file2,line);stringstream(line)>>weight;L.Set_part_weight(weight);
					    getline(file2,line);stringstream(line)>>loco_speed;L.set_max_speed(loco_speed);
					    getline(file2,line);stringstream(line)>>loco_power;L.set_max_power(loco_power);	
					    shop::add_component(&L);
					    i+=9;
					    break;
				case 4: 
					    getline(file2,line);name=line;H.Set_part_name(name);
					    getline(file2,line);model_num=line;H.set_part_model_num(model_num);
					    getline(file2,line);description=line;H.Set_part_description(description);
					    getline(file2,line);image=line;H.Set_part_image(image);
					    getline(file2,line);stringstream(line)>>cost;H.Set_part_cost(cost);	
					    getline(file2,line);stringstream(line)>>weight;H.Set_part_weight(weight);
					    getline(file2,line);stringstream(line)>>head_power;H.set_head_power(head_power);
					    shop::add_component(&H);
					    i+=8;
					    break;
				case 5: 
					    getline(file2,line);name=line;B.Set_part_name(name);
					    getline(file2,line);model_num=line;B.set_part_model_num(model_num);
					    getline(file2,line);description=line;B.Set_part_description(description);
					    getline(file2,line);image=line;B.Set_part_image(image);
					    getline(file2,line);stringstream(line)>>cost;B.Set_part_cost(cost);	
					    getline(file2,line);stringstream(line)>>weight;B.Set_part_weight(weight);
					    getline(file2,line);stringstream(line)>>batt_power;B.set_batt_power(batt_power);
					    getline(file2,line);stringstream(line)>>batt_energy;B.set_batt_energy(batt_energy);
					    shop::add_component(&B);
					    i+=9;	
					    break;
							}
		}
		file2.close();
	}
}
void shop::Read_Robot_Models(){
	
}
void shop::Read_SA_List(){
	
	
}
void shop::Read_PHB_info(){
	
}
void shop::Read_PM_info(){
	
}
/****************** PHB AND SA ******************/

void  shop::Give_Deny_Raise_SA(int index, int yes_No){
   if(yes_No ==1){
	     int X = Sales_Associate_of_Shop[index]->number_of_processed_orders();
	     double Raise_by = X * 10; /* 10 dollars per Processed Order */
	     Sales_Associate_of_Shop[index]->Give_Raise(Raise_by);
   }
   else
   {
	    Sales_Associate_of_Shop[index]->Give_Raise(0.0);
   }
}
/****************** Process Order ******************/
void shop::Process_Order(int index){
	
}
























