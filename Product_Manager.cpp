#include "Product_Manager.h"
#include "Model.h"
#include "shop.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/******************* Setting Default Values for name and Password *********************/
string Product_Manager::manager_name = "Manager_Default";
string Product_Manager::manager_password = "Manager_Default";
/******************* Get Instance *********************/
Product_Manager& Product_Manager::get_Instance(){
static Product_Manager instance;
	return instance;	
}
/******************* check name and password *********************/
bool Product_Manager::check_name_pass(string in_name, string in_pass){
   if(in_name != manager_name || in_pass !=manager_password)
	   return 0;
	else 
		return 1;	
}
/******************* Change Name/Pass *********************/
void Product_Manager::change_name(string new_name){
     manager_name = new_name;
}
void Product_Manager::change_pass(string new_pass){
	manager_password = new_pass;
}
/******************* Instance Arm *********************/
void Product_Manager::Instance_new_Arm(string name, string model_number, string description, string image_filename,
									   double cost, double weight,double max_power)
{   
	Arm temp(name,model_number,description,image_filename,cost,weight,max_power);
		push_component(temp);
}
/******************* Instance Torso *********************/
void Product_Manager::Instance_new_Torso(string name, string model_number, string description, string image_filename, double cost,
										 double weight, int max_arms, int battery_compartments)
{   
	Torso temp(name,model_number,description,image_filename,cost,weight,max_arms,battery_compartments);
	push_component(temp);
}
/******************* Instance Locomotor *********************/
void Product_Manager::Instance_new_Locomotor(string name, string model_number, string description, string image_filename, double cost,
											 double weight, double max_speed, double max_power)
{   
	Locomotor temp(name,model_number,description,image_filename,cost,weight,max_speed,max_power);
	push_component(temp);
}
/******************* Instance Head *********************/
void Product_Manager::Instance_new_Head(string name, string model_number, string description, string image_filename, 
										double cost, double weight,double max_power)
{   
	Head temp(name,model_number,description,image_filename,cost,weight,max_power);
	push_component(temp);
}
/******************* Instance Battery *********************/
void Product_Manager::Instance_new_Battery(string name, string model_number,string description,string image_filename, 
										   double cost,double weight, double power_available, double max_energy)
{   
	Locomotor temp(name,model_number,description,image_filename,cost,weight,power_available,max_energy);
	push_component(temp);
}
/******************* Instance Model *********************/
void Product_Manager::Instance_new_model(string m_name,string m_number)
{
	Robot_model temp(m_name,m_number);
  	push_Model(temp);
	
}
/******************* Push Component/Model *********************/
void Product_Manager::push_component(Robot_Part& temp)
{
	shop::add_component(&temp);
	
}
void Product_Manager::push_Model(Robot_model& temp)
{
	shop::add_Model(&temp);	
}
/******************* Pull Component/Model *********************/
void   Product_Manager::pull_component(int component_index){
	shop::remove_component(component_index);
}
void   Product_Manager::pull_Model(int Model_index){
	shop::remove_Model(Model_index);
}






