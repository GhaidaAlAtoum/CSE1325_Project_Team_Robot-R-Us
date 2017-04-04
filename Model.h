#ifndef model_H
#define model_H
#include "Robot_part.h"
#include "Components.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Robot_model 
{
	private:  
	     double model_Price=0.0;
	     string    model_name ="No_Name";
	     string       model_number="0";
	     vector<Torso>     model_Torso;
	     vector<Head>      model_Head;
	     vector<Locomotor> model_Locomotor;
	     vector<Battery> model_Battery;
	     vector<Arm> model_Arm;
         
	public:
	/******************* Constructor *********************/
	      Robot_model();
	      Robot_model(string,string);
	/******************* Print Model Components *********************/   
		  string print_model_Components();
   /******************* Get *********************/
          string Get_model_name ();  //done
	      string Get_model_number () ;//done
		  string Get_Torso_part_name();//done
		  string Get_Torso_part_number();//done
		  string Get_locomotor_part_name();//done
		  string Get_locomotor_part_number();//done
		  string Get_Head_part_name();//done
		  string Get_Head_part_number();//done
   vector<string> Get_each_Battery_name();//done
   vector<string> Get_each_Battery_number();//done
   vector<string> Get_each_Arm_name();//done
   vector<string> Get_each_Arm_number();//done
		  int    Get_number_of_Arms() ;//done
	      int    Get_number_of_Batteries();//done
		  int    Get_Torso_Bat_Comp();//done
	      int    Get_Torso_Max_arms();//done
		  int    Get_Head_power();//done
   vector<double> Get_Battery_available_power();//done
   vector<double> Get_Battery_max_energy();//done
		  double Get_Locomotor_max_speed();//done
	      double Get_Locomotor_max_power();//done
		  double Get_Model_Cost();
		  double Get_Model_Shipping_Cost();
   vector<double> Get_Arms_power() ;
    /******************* Add *********************/
          bool   add_Torso(Torso);
	      bool   add_Head(Head);
	      bool   add_Locomotor(Locomotor);
		  bool   add_Arm(Arm);
	      void   add_Battery(Battery);
    /***************** Set ********************/
	      void Set_Cost(double);
	      

};
#endif