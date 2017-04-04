#include "Robot_part.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
Robot_Part::Robot_Part()
{

  name = "no name"; 
  model_number ="00000";
  cost = 0.0;
  description = "no description";
  image_filename = "default.jpg";
  weight = 0.0;

}

Robot_Part::Robot_Part(string in_name,
		       string in_model_number, string in_description,
		       string in_image_filename, double in_cost, double in_weight) 
{

  name = in_name; 
  model_number = in_model_number;
  cost = in_cost;
  description = in_description;
  image_filename = in_image_filename;
  weight = in_weight;

}
double Robot_Part::get_cost() {return cost;}
double Robot_Part::get_shipping_price() {return (weight * 1.8);}
double Robot_Part::get_weight(){return weight; }
string Robot_Part::get_image_filename() {return image_filename;}
string Robot_Part::get_part_name() {return name; }
string Robot_Part::get_part_description(){ return description;}
string Robot_Part::get_part_number(){return model_number;}
void   Robot_Part::Set_part_name(string temp){
	    name=temp; }
void   Robot_Part::set_part_model_num(string temp){
          model_number=temp;
}
void   Robot_Part::Set_part_description(string temp){
          description=temp;
}
void   Robot_Part::Set_part_image(string temp){
         image_filename=temp;
}
void   Robot_Part::Set_part_cost(double temp){
         cost =temp;
}
void   Robot_Part::Set_part_weight(double temp){
         weight=temp;	
}



