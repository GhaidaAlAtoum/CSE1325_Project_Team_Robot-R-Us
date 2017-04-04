#ifndef Components_H
#define Components_H
#include "Robot_part.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/********************************** Arm Class **********************************/
class Arm:public Robot_Part
{

private:
 
  double max_power;
public:
  Arm();
  Arm(string, string, string, string, double, double,double);
  double get_max_power_Arm();
  int Type(){ return 1; }
  void set_arm_power(double temp){ max_power = temp; }
  
};
/********************************** Torso class **********************************/

class Torso:public Robot_Part
{
private:
  
  int battery_compartments;
  int max_arms;
public:
  Torso();
  Torso(string, string, string, string, double, double, int, int);
  int Type(){ return 2; } 
  int get_battery_compartments();
  int get_max_arms();
  void set_Torso_batt(int temp){ }
  void set_Torso_max_arms(int temp){ }
};
/********************************** Locomotor class **********************************/

class Locomotor:public Robot_Part
{
private: 
  double max_power;
  double max_speed;
public:
  int Type(){ return 3; }
  Locomotor();
  Locomotor(string, string, string, string, double,double, double, double);
  double get_max_speed(){ return max_speed;}
  double get_max_power(){ return max_power;}
  void set_max_power(double temp){ max_power = temp; }
  void set_max_speed(double temp){ max_speed =temp; }
};
/********************************** Head class **********************************/

class Head:public Robot_Part
{

private:
  
  double power;
public:
  int Type(){ return 4; }
  Head();
  Head(string, string, string, string, double, double,double);
  double Getpower();
  void set_head_power(double temp){ power = temp; }
};
/********************************** Battery class **********************************/

class Battery:public Robot_Part
{
private:
 
  double power_available;
  double max_energy;
public:
  int Type(){ return 5; }
  Battery();
  Battery(string, string,string,string, double,double, double, double);
  double get_power();
  double get_max_energy();
  void set_batt_power(double temp){ power_available=temp; }
  void set_batt_energy(double temp){ max_energy=temp; }
};
#endif