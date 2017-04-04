#ifndef ROBOT_PART_H
#define ROBOT_PART_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Robot Class and all its Functions

class Robot_Part
{
protected:
  string name;
  string model_number;
  double cost;
  string description;
  string image_filename;
  double weight;
  
public:

  Robot_Part();
  Robot_Part(string, string, string, string, double, double);
  /************ GET functions **************/
  double get_cost();
  double get_shipping_price();
  double get_weight();
  string get_image_filename();
  string get_part_description();
  string get_part_name();
  string get_part_number();
  /************ SET functions **************/
  void   Set_part_name(string);
  void   set_part_model_num(string);
  void   Set_part_description(string);
  void   Set_part_image(string);
  void   Set_part_cost(double);
  void   Set_part_weight(double);
  /******** Virtual Functions ********/
  virtual int    Type()=0;
  virtual double get_max_power_Arm() { return 0;}
  virtual int get_max_arms(){return 0; }
  virtual int get_battery_compartments() { return 0;}
  virtual double get_max_power(){return 0; }
  virtual double get_max_speed() { return 0;}
  virtual double Getpower() {return 0; }
  virtual double get_power() {return 0; }
  virtual double get_max_energy() {return 0;}
  
 
};

#endif