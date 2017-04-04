#include "Robot_part.h"
#include "Components.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/********************************** Arm Class **********************************/
Arm::Arm()
:Robot_Part() 
{
 max_power=0;
}

Arm::Arm(string in_name,string in_model_number,string in_description,
	 string in_image_filename, double in_cost,double in_weight, double in_max_power)
  :Robot_Part(in_name,
        in_model_number,in_description,
	in_image_filename, in_cost,
	in_weight) 
{
  max_power = in_max_power;
	}

double Arm::get_max_power_Arm() {
	return (max_power);
}
/********************************** Torso class **********************************/
Torso::Torso():Robot_Part()
{

  battery_compartments = 0;
  max_arms = 0;

}

Torso::Torso(string in_name,
	     string in_model_number, string in_description,
	     string in_image_filename, double in_cost,
	     double in_weight, int in_max_arms,
	     int in_battery_compartments)
	:Robot_Part(in_name,
		       in_model_number, in_description,
		       in_image_filename, in_cost, in_weight)
{
  battery_compartments = in_battery_compartments;
  max_arms = in_max_arms;

}
int Torso::get_battery_compartments(){
   return battery_compartments;
}
int Torso::get_max_arms(){
	return max_arms;}
/********************************** Locomotor class **********************************/
Locomotor::Locomotor()
{

  max_power = 0;
  max_speed = 0;
  
}

Locomotor::Locomotor(string in_name,
		       string in_model_number, string in_description,
		       string in_image_filename, double in_cost,
		     double in_weight, double in_max_speed,
		     double in_max_power):Robot_Part(in_name,
		     in_model_number, in_description,
		     in_image_filename, in_cost, in_weight)
{

  max_speed = in_max_speed;
  max_power = in_max_power;
  
}

/********************************** Head class **********************************/
Head::Head()
:Robot_Part() 
{
   power = 0;
}

Head::Head(string in_name,string in_model_number,string in_description,
         string in_image_filename, double in_cost,double in_weight, double in_max_power)
  :Robot_Part(in_name,
        in_model_number,in_description,
        in_image_filename, in_cost,
        in_weight)
{
  power = in_max_power;
}

double Head::Getpower() {return power;}

/********************************** Battery class **********************************/
Battery::Battery()
:Robot_Part() 
{
  power_available = 0.0;
  max_energy = 0.0;
}
Battery::Battery(string in_name,string in_model_number,string in_description,
         string in_image_filename, double in_cost,double in_weight, double in_power_available, double in_max_energy)
  :Robot_Part(in_name,
        in_model_number,in_description,
        in_image_filename, in_cost,
        in_weight)
{
  power_available = in_power_available;
  max_energy = in_max_energy;
  
}
double Battery::get_power() {return power_available;}
double Battery::get_max_energy() {return max_energy;}





