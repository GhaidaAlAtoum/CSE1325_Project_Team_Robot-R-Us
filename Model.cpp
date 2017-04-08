#include "shop.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include "Sales_Associate.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
/******************* Constructor *********************/
Robot_model::Robot_model() {}
Robot_model::Robot_model(string in_name , string in_num){
           model_name = in_name;
	       model_number = in_num;
}
/******************* Add Arm *********************/
bool Robot_model::add_Arm(Arm in_Arm){
	if(model_Arm.size()<2) {
	     model_Arm.push_back(in_Arm);
		return 1;
	 }
	else {
	     return 0;
	}
}
/******************* Add Torso *********************/
bool Robot_model::add_Torso(Torso in_Torso){
	if(model_Torso.size()==0) {
	     model_Torso.push_back(in_Torso);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
/******************* Add Locomotor *********************/
bool Robot_model::add_Locomotor(Locomotor in_Locomotor){
		if(model_Locomotor.size()==0) {
	     model_Locomotor.push_back(in_Locomotor);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
/******************* Add Head *********************/
bool Robot_model::add_Head(Head in_Head){
		if(model_Head.size()==0) {
	     model_Head.push_back(in_Head);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
/******************* Add Battery *********************/
void Robot_model::add_Battery(Battery in_Battery){
	model_Battery.push_back(in_Battery);
		}
/******************* Get Arm(s) Info  *********************/
double Robot_model::Get_Arms_power(int index) {
    double power=0.0;
	if(model_Arm.size()!=0){
		power=model_Arm[index].get_max_power_Arm();
	 	} //end if
	   return power;
}
string Robot_model::Get_each_Arm_name(int index){
	string temp;
	if(model_Arm.size()!=0){
	    temp=model_Arm[index].get_part_name();
		}
	return (temp);
}
string Robot_model::Get_each_Arm_number(int index){
	string temp;
	if(model_Arm.size()!=0){
		temp=model_Arm[index].get_part_number();
	}
	return (temp);
}
/******************* Get Torso Info  *********************/
int  Robot_model::Get_Torso_Bat_Comp () {
	if(model_Torso.size()!=0) 
		return model_Torso[0].get_battery_compartments();
    else
        return 0;}
int    Robot_model::Get_Torso_Max_arms() { 
	if(model_Torso.size()!=0)
	return  model_Torso[0].get_max_arms (); 
	else
		return 0;
} 	
string Robot_model::Get_Torso_part_name(){
	if(model_Torso.size()!=0) 
	return(model_Torso[0].get_part_name());
	else
		return("NONE");
}
string Robot_model::Get_Torso_part_number(){
	if(model_Torso.size()!=0) 
     return(model_Torso[0].get_part_number());
	else
		return("NONE");
}
/******************* Get Locomotor Info  *********************/
double Robot_model::Get_Locomotor_max_speed() {
	if(model_Locomotor.size()!=0)
	return  model_Locomotor[0].get_max_speed();
	else 
		return 0;
}
double Robot_model::Get_Locomotor_max_power() { 
	if(model_Locomotor.size()!=0)
	return  model_Locomotor[0].get_max_power();
	else
		return 0;
}
string Robot_model::Get_locomotor_part_name(){
	if(model_Locomotor.size()!=0)
	return(model_Locomotor[0].get_part_name());
	else
		return("NONE");
}
string Robot_model::Get_locomotor_part_number(){
	if(model_Locomotor.size()!=0)
     return(model_Locomotor[0].get_part_number());
	else
		return("NONE");
}
/******************* Get Head Info  *********************/
int    Robot_model::Get_Head_power() {
	if(model_Head.size()!=0)
	return model_Head[0].Getpower();
	else
		return 0;
}
string Robot_model::Get_Head_part_name(){
	if(model_Head.size()!=0){
	return(model_Head[0].get_part_name());}
	else{
		string temp =" NONE ";
		return temp;}
}
string Robot_model::Get_Head_part_number(){
    if(model_Head.size()!=0){ 
	return(model_Head[0].get_part_number());}
	else{
		string temp =" NONE ";
		return temp;}
}
/******************* Get Battery Info  *********************/
double Robot_model::Get_Battery_available_power(int index) {
    double power ;
	if(model_Battery.size()!=0){
		power=model_Battery[index].get_power();  
	} //end if
	return power;
}
double Robot_model::Get_Battery_max_energy(int index) {
    double energy ;
	if(model_Battery.size()!=0){
		energy=model_Battery[index].get_max_energy(); 
	} //end if
	   return energy;
}
string Robot_model::Get_each_Battery_name(int index){
	string temp;
	if(model_Battery.size()!=0){
		temp=model_Battery[index].get_part_name();
 }
	return (temp);
}
string Robot_model::Get_each_Battery_number(int index){
	string temp;
	if(model_Battery.size()!=0){
		temp=model_Battery[index].get_part_number();
	}
	return (temp);
}
/******************* Get Number of Arms   *********************/
int Robot_model::Get_number_of_Arms() { 
	return model_Arm.size();
}
/******************* Get Number of Batteries   *********************/
int Robot_model::Get_number_of_Batteries(){
	return model_Battery.size();
}
/******************* Get Torso Exist  *********************/
bool Robot_model::Get_Torso_Exist(){
	if(model_Torso.size()!=0)
		return 1;
	else
		return 0;
}
/******************* Get Loco Exist  *********************/
bool Robot_model::Get_Loco_Exist(){
		if(model_Locomotor.size()!=0)
		return 1;
	else
		return 0;
}
/******************* Get Head Exist  *********************/
bool Robot_model::Get_Head_Exist(){
		if(model_Head.size()!=0)
		return 1;
	else
		return 0;
}
/******************* Get Model Cost (Theoritical) *********************/
double Robot_model::Get_Model_Cost(){
    double cost=0.0;
	double shipping=0.0;
	if(model_Arm.size()!=0){
	 for( auto & num : model_Arm ){
	     cost += num.get_cost() ;
	 } 
	} 
	if(model_Battery.size()!=0){
	 for( auto & num : model_Battery ){
	     cost += num.get_cost();
	 } 
	} 
	cost += model_Torso[0].get_cost();
	cost += model_Head[0].get_cost();
	cost += model_Locomotor[0].get_cost();
	shipping=this->Get_Model_Shipping_Cost();
	cost += shipping;
	return cost;
}
/******************* Get Model Shipping Cost   *********************/
double Robot_model::Get_Model_Shipping_Cost(){
	  double cost=0.0;
	if(model_Arm.size()!=0){
	 for( auto & num : model_Arm ){
	     cost += num.get_shipping_price();
	 } 
	} 
	if(model_Battery.size()!=0){
	 for( auto & num : model_Battery ){
	     cost += num.get_shipping_price();
	 } 
	} 
	cost +=  model_Torso[0].get_shipping_price();
	cost +=  model_Head[0].get_shipping_price();
	cost +=  model_Locomotor[0].get_shipping_price();
	return cost;
}
/******************* Get Model name   *********************/
 string Robot_model::Get_model_name () {
	 return model_name; 
 }
/******************* Get Model number *********************/
 string Robot_model::Get_model_number () { 
	 return model_number ;
 }
/******************* Get Model PRICE *********************/
double  Robot_model::Get_model_Price(){
   return(model_Price);
}
/*****************   Set Model Price ********************/
void Robot_model::Set_Cost(double temp){
    model_Price=temp;
}
/******************* Print Model *********************/
string Robot_model::print_model_Components(){
	

}



