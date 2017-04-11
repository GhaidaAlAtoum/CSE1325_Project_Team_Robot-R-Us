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
	      /////////////////////////////////// Constructor ///////////////////////////////////////
	      Robot_model();
	      Robot_model(string,string);
	      ////////////////////////////////// Print Model Components /////////////////////////////  
		  string print_model_Components();
          ///////////////////////////////// Get ///////////////////////////////////////////////
          string Get_model_name ();  
	      string Get_model_number () ;
		  double Get_model_Price();
          /******************* Get Arm(s) Info  *********************/   
          string Get_each_Arm_name(int);
          string Get_each_Arm_number(int);
		  double Get_Arms_power(int) ;
		  int    Get_number_of_Arms();
          /******************* Get Torso Info  *********************/
		  string Get_Torso_part_name();
		  string Get_Torso_part_number();
		  int    Get_Torso_Bat_Comp();
	      int    Get_Torso_Max_arms();
		  bool    Get_Torso_Exist();
          /******************* Get Locomotor Info  *********************/
		  string Get_locomotor_part_name();
		  string Get_locomotor_part_number();
 		  double Get_Locomotor_max_speed();
          double Get_Locomotor_max_power();
		  bool    Get_Loco_Exist();
          /******************* Get Head Info  *********************/		  
		  bool    Get_Head_Exist();
		  string Get_Head_part_name();
		  string Get_Head_part_number();
          int    Get_Head_power();
          /******************* Get Battery Info  *********************/		  
          double Get_Battery_available_power(int);
          double Get_Battery_max_energy(int);
          string Get_each_Battery_name(int);
          string Get_each_Battery_number(int);
		  int    Get_number_of_Batteries(); 
          /******************* Get Model Cost (Theoritical) *********************/	      
		  double Get_Model_Cost();
          /******************* Get Model Shipping Cost (From The weights of each component)************/		  
		  double Get_Model_Shipping_Cost();
          /////////////////////////////////// Add ///////////////////////////////////////////////
          bool   add_Torso(Torso);
	      bool   add_Head(Head);
	      bool   add_Locomotor(Locomotor);
		  bool   add_Arm(Arm);
	      void   add_Battery(Battery);
         //////////////////////////////////// Set ///////////////////////////////////////////////
	     /*****************   Set Model Price ********************/
	      void Set_Cost(double);
	      

};
#endif