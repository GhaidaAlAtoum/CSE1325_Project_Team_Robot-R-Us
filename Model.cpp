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
Robot_model::Robot_model(istream& input){      int i=0;
       int j=1;
       int type =0;
	   model_name = get_string(input);
	   model_number = get_string(input);
	   model_Price = get_double(input);
       i=get_int(input);
      for(;j<=i;j++){
	   type=get_int(input);
			switch(type) {
				case 1: 
                        model_Arm.push_back(Arm(input));
					    break;
				case 2: 
                        model_Torso.push_back(Torso(input));				
					    break;
				case 3: 
                        model_Locomotor.push_back(Locomotor(input));
					    break;
				case 4: 
                        model_Head.push_back(Head(input));
					    break;
				case 5: 
                        model_Battery.push_back(Battery(input));	
					    break;
					
			}
	  }
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
/*****************   Get Number_of_comp ********************/
int Robot_model::Get_Number_of_comp(){
	int j=0;
	j+=Get_number_of_Arms();
	if(Get_Torso_Exist()) j++;
	if(Get_Loco_Exist()) j++;
	if(Get_Head_power()) j++;
	j+=Get_number_of_Batteries();
	return j;
	
}
/******************* Get Model Battery Life *********************/
 double Robot_model::Battery_Life () { 
 	 double sum =0.0;
	 double sum_Arm=0.0; 
	 double sum_batt=0.0;
     sum += Get_Head_power() + 0.15*(Get_Locomotor_max_power());
	 if((this->Get_number_of_Arms() )!=0){
	     for(auto & num : model_Arm){
		    sum_Arm += (num.get_max_power_Arm());
		 }
		 sum_Arm *= 0.4;
	 }
	 sum += sum_Arm;
	 if((this->Get_number_of_Batteries())!=0){
		 for(auto & num : model_Battery){
			 sum_batt += num.get_max_energy();
		 }
	 }
	 return (sum/(sum_batt)) ;
 }
 /******************* Get Model Power Limited *********************/
 bool Robot_model::Power_Limited () { 
  double sum =0.0;
  double sum_batt=0.0;
  sum += Get_Head_power() + Get_Locomotor_max_power();
   if((this->Get_number_of_Arms() )!=0){
	     for(auto & num : model_Arm){
		    sum += (num.get_max_power_Arm());
		 }
	 }
	 if((this->Get_number_of_Batteries())!=0){
		 for(auto & num : model_Battery){
			 sum_batt += num.get_max_energy();
		 }
	 }
	 return(sum>sum_batt);
 }
 /******************* Get Model Total Weight *********************/
double Robot_model::Model_total_weight(){
 double temp =0.0;
   for(auto & num : model_Arm){
		temp += num.get_weight();
	}
	if(Get_Torso_Exist()){
		temp +=model_Torso[0].get_weight();
	}
	if(Get_Loco_Exist()){
		temp +=model_Locomotor[0].get_weight();
	}
	if(Get_Head_power()){
	temp +=model_Head[0].get_weight();
	}
	for(auto & num : model_Battery){
      temp += num.get_weight();
	}
	return temp;
}
 /******************* Get Model max speed *********************/
double Robot_model::Model_max_speed(){
  double temp=0.0;
  double speed = Get_Locomotor_max_speed();
  double weight= Model_total_weight();
  double loco_weight = 0.0;
	if(Get_Loco_Exist()){
		loco_weight=model_Locomotor[0].get_weight();
	}
  if( (loco_weight*5) >= weight){
	 return speed;
  }
  else {
	return (speed * ((loco_weight*5)/weight)); 
  }
	
}
/******************* save and ostream Model *********************/
void Robot_model::save(ostream & output_save){
	output_save << model_name <<endl;
	output_save << model_number <<endl;
	output_save << model_Price <<endl;
	output_save << Get_Number_of_comp() <<endl;
	for(auto & num : model_Arm){
		output_save<<1<<endl;
		num.save(output_save);
	}
	if(Get_Torso_Exist()){
		output_save<<2<<endl;
		model_Torso[0].save(output_save);}
	if(Get_Loco_Exist()){
		output_save<<3<<endl;
		model_Locomotor[0].save(output_save);}
	if(Get_Head_power()){
		output_save<<4<<endl;
		model_Head[0].save(output_save);}
	for(auto & num : model_Battery){
		output_save<<5<<endl;
		num.save(output_save);
	}
	
}
ostream& operator<<(ostream& out, Robot_model &model){
 //Name	 Number	 price	 Weight Battery Life 	Max Speed
 out<<std::left<<std::setfill(' ')<<std::setw(20)<<model.model_name
	   <<std::left<<std::setfill(' ')<<std::setw(20)<<model.model_number
	   <<"$"<<std::left<<std::setfill(' ')<<std::setw(10)<<model.model_Price
	   << "pound "<<std::left<<std::setfill(' ')<<std::setw(10)<<model.Model_total_weight()
	   << "Hours "<<std::left<<std::setfill(' ')<<std::setw(20)<<model.Battery_Life()
	 <<" MPH"<<std::left<<std::setfill(' ')<<std::setw(10)<<model.Model_max_speed()<<endl;
	return out;
}





























