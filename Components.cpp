#include "Robot_part.h"
#include "Components.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/********************************** Arm Class **********************************/
Arm::Arm()
:Robot_Part() {
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
Arm::Arm(ifstream& input)
	 :Robot_Part(get_string(input),get_string(input),get_string(input),get_string(input),
	 get_double(input),get_double(input))
	 { 
	max_power=get_double(input);
}
double Arm::get_max_power_Arm() {
	return (max_power);
}
/******************** Arm Save To file Function ********************/
  void Arm::save  (ostream& output_save){
	  output_save<<get_part_name()<<endl;
	  output_save<<get_part_number()<<endl;
	  output_save<<get_part_description()<<endl;
	  output_save<<get_image_filename()<<endl;
	  output_save<<get_cost()<<endl;
	  output_save<<get_weight()<<endl;
	  output_save<<get_max_power_Arm()<<endl;
  }
/******************** Arm print to text ********************/
  ostream& operator<<(ostream& output_print, Arm & arm){
   // Name[20]	Number[20]	Cost[5]	Weight[5] power[5]
   // description:    
   string power = "Power = ";
   string descrip = "description: "
	output_print<<std::left<<std::setfill(' ')<<std::setw(20)<<arm.get_part_name()
	            <<std::left<<std::setfill(' ')<<std::setw(20)<<arm.get_part_number()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<arm.get_cost()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<arm.get_weight()
				<<std::left<<std::setfill(' ')<<std::setw(8)<<power
				<<std::left<<std::setfill(' ')<<std::setw(5)<<arm.get_max_power_Arm()
				<<"\n"<<arm.descrip<<get_part_description()<<endl;
    return output_print;
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
Torso::Torso(ifstream& input)
:Robot_Part(get_string(input),get_string(input),get_string(input),get_string(input),
	 get_double(input),get_double(input))
	 {
	    max_arms=get_int(input);
		battery_compartments=get_int(input);
	 }
int Torso::get_battery_compartments(){
   return battery_compartments;
}
int Torso::get_max_arms(){
	return max_arms;}
/******************** Torso Save To file Function ********************/
  void Torso::save  (ostream& output_save){
	  output_save<<get_part_name()<<endl;
	  output_save<<get_part_number()<<endl;
	  output_save<<get_part_description()<<endl;
	  output_save<<get_image_filename()<<endl;
	  output_save<<get_cost()<<endl;
	  output_save<<get_weight()<<endl;
	  output_save<<get_max_arms()<<endl;
	  output_save<<get_battery_compartments()<<endl;
  }
/******************** Torso print to text ********************/
  ostream& operator<<(ostream& output_print, Torso & torso){
   // Name[20]	Number[20]	Cost[5]	Weight[5] arms[4] battery_compartments[4]
   // description:   
      
   string arms = "Max number of Arms : ";
   string batt_comp="Battery compartments : ";
   string descrip = "description: "
	output_print<<std::left<<std::setfill(' ')<<std::setw(20)<<torso.get_part_name()
	            <<std::left<<std::setfill(' ')<<std::setw(20)<<torso.get_part_number()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<torso.get_cost()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<torso.get_weight()
				<<std::left<<std::setfill(' ')<<std::setw(21)<<arms
				<<std::left<<std::setfill(' ')<<std::setw(4)<<torso.get_max_arms()
				<<std::left<<std::setfill(' ')<<std::setw(23)<<batt_comp
				<<std::left<<std::setfill(' ')<<std::setw(4)<<torso.get_battery_compartments()
				<<"\n"<<descrip<<torso.get_part_description()<<endl;
    return output_print;
  }

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
Locomotor::Locomotor(ifstream& input)
:Robot_Part(get_string(input),get_string(input),get_string(input),get_string(input),
	 get_double(input),get_double(input))
{
	max_speed=get_double(input);
	max_power=get_double(input);
}
/******************** Locomotor Save To file Function ********************/
  void Locomotor::save  (ostream& output_save){
	  output_save<<get_part_name()<<endl;
	  output_save<<get_part_number()<<endl;
	  output_save<<get_part_description()<<endl;
	  output_save<<get_image_filename()<<endl;
	  output_save<<get_cost()<<endl;
	  output_save<<get_weight()<<endl;
	  output_save<<get_max_speed()<<endl;
	  output_save<<get_max_power()<<endl;
  }
/******************** Locomotor print to text ********************/
  ostream& operator<<(ostream& output_print, Locomotor & loco){
   // Name[20]	Number[20]	Cost[5]	Weight[5] speed[4] power[4]
   // description:   
      
   string speed = "Speed : ";
   string power = "Power : ";
   string descrip = "description: "
	output_print<<std::left<<std::setfill(' ')<<std::setw(20)<<loco.get_part_name()
	            <<std::left<<std::setfill(' ')<<std::setw(20)<<loco.get_part_number()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<loco.get_cost()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<loco.get_weight()
				<<std::left<<std::setfill(' ')<<std::setw(8)<<speed
				<<std::left<<std::setfill(' ')<<std::setw(4)<<loco.get_max_speed()
				<<std::left<<std::setfill(' ')<<std::setw(8)<<power
				<<std::left<<std::setfill(' ')<<std::setw(4)<<loco.get_max_power()
				<<"\n"<<descrip<<loco.get_part_description()<<endl;
    return output_print;
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
Head::Head(ifstream& input)
:Robot_Part(get_string(input),get_string(input),get_string(input),get_string(input),
	 get_double(input),get_double(input))
{
	power=get_double(input);
}
double Head::Getpower() {return power;}
/******************** Head Save To file Function ********************/
  void Head::save  (ostream& output_save){
	  output_save<<get_part_name()<<endl;
	  output_save<<get_part_number()<<endl;
	  output_save<<get_part_description()<<endl;
	  output_save<<get_image_filename()<<endl;
	  output_save<<get_cost()<<endl;
	  output_save<<get_weight()<<endl;
	  output_save<<Getpower()<<endl;
  }
/******************** Head print to text ********************/
  ostream& operator<<(ostream& output_print, Head & head){
   // Name[20]	Number[20]	Cost[5]	Weight[5]  power[4]
   // description:   
   string power = "Power : ";
   string descrip = "description: "
	output_print<<std::left<<std::setfill(' ')<<std::setw(20)<<head.get_part_name()
	            <<std::left<<std::setfill(' ')<<std::setw(20)<<head.get_part_number()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<head.get_cost()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<head.get_weight()
				<<std::left<<std::setfill(' ')<<std::setw(8)<<power
				<<std::left<<std::setfill(' ')<<std::setw(4)<<head.Getpower()
				<<"\n"<<descrip<<head.get_part_description()<<endl;
    return output_print;
  }
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
Battery::Battery(ifstream& input)
:Robot_Part(get_string(input),get_string(input),get_string(input),get_string(input),
	 get_double(input),get_double(input))
{
	power_available=get_double(input);
	max_energy=get_double(input);
}
double Battery::get_power() {return power_available;}
double Battery::get_max_energy() {return max_energy;}
/******************** Battery Save To file Function ********************/
  void Battery::save  (ostream& output_save){
	  output_save<<get_part_name()<<endl;
	  output_save<<get_part_number()<<endl;
	  output_save<<get_part_description()<<endl;
	  output_save<<get_image_filename()<<endl;
	  output_save<<get_cost()<<endl;
	  output_save<<get_weight()<<endl;
	  output_save<<get_power()<<endl;
	  output_save<<get_max_energy()<<endl;
  }
/******************** Battery print to text ********************/
  ostream& operator<<(ostream& output_print, Battery & battery){
   // Name[20]	Number[20]	Cost[5]	Weight[5]  power[4]
   // description:   
   string power =  "Power : ";
   string energy = "Energy : ";
   string descrip = "description: "
	output_print<<std::left<<std::setfill(' ')<<std::setw(20)<<battery.get_part_name()
	            <<std::left<<std::setfill(' ')<<std::setw(20)<<battery.get_part_number()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<battery.get_cost()
				<<std::left<<std::setfill(' ')<<std::setw(5)<<battery.get_weight()
				<<std::left<<std::setfill(' ')<<std::setw(8)<<power
				<<std::left<<std::setfill(' ')<<std::setw(4)<<battery.get_power()
				<<std::left<<std::setfill(' ')<<std::setw(10)<<energy
				<<std::left<<std::setfill(' ')<<std::setw(4)<<battery.get_max_energy()
				<<"\n"<<descrip<<battery.get_part_description()<<endl;
    return output_print;
  }



