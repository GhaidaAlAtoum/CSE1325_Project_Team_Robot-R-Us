#include "shop.h"
#include "Sales_Associate.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include <iomanip>
#include<cstdio>

using namespace std;
vector <Robot_Part*> shop::components;
vector <Robot_model*> shop::Models;
vector <customer> shop::shop_Customers;
Product_Manager shop::shop_Product_Manager = Product_Manager::get_Instance();
vector <Order*> shop::shop_processed_Orders ; 
vector <Order*>  shop::shop_unprocessed_Orders ;
vector <SA*> shop::Sales_Associate_of_Shop;
int shop::num_orders=0;
shop& shop::Instance_shop( ){
	static shop instance;
           return instance;
}
/****************** ADD ********************/
void shop::add_PM(Product_Manager & temp){
 shop_Product_Manager=temp;	
}
void shop::add_component(Robot_Part * temp){
	   	components.push_back(temp);
}
void shop::add_Model(Robot_model* temp){
    	Models.push_back(temp);
}
Order shop::add_Order(int model_index,int Quantity,string Name){
	 int num = num_orders;
	 Robot_model temp_model= *(Models[model_index]);
	 Order *temp =new Order(num,temp_model,Name);
     shop_unprocessed_Orders.push_back(temp);
	 num_orders++;
	cout<<"Order Number "<<num<<" Model Name "<<Models[model_index]->Get_model_name()<<" Quantity "<<Quantity<<endl;
	 return(*(temp));
}
void shop::add_SA(SA * temp){
	for(auto & num : Sales_Associate_of_Shop){
		if((num->Get_SA_Name())==(temp->Get_SA_Name())){
		 cout<<" ERROR THIS NAME EXIST IN THE SA LIST\n WILL NOT BE ADDED\n";
			return;
		} }
     shop::Sales_Associate_of_Shop.push_back(temp);
}
/****************** REMOVE ********************/
void shop::remove_component(int index){
	    components.erase(components.begin() + index);
}
void shop::remove_Model(int index){
	Models.erase(Models.begin() + index);
}
void shop::remove_SA(int index){
	    Sales_Associate_of_Shop.erase(Sales_Associate_of_Shop.begin()+index);
}
/****************** PRINT********************/
void shop::Print_Catalog_Models(){
	cout<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(10)<<"Price"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Weight"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Battery Life"
		<<std::left<<std::setfill(' ')<<std::setw(10)<<"Max Speed"<<endl;
	for( auto & num : Models ){
	    cout<< *((Robot_model*)(num));
	}
}
void shop::Print_Catalog_Components(){
	cout<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(5)<<"Cost"
		<<std::left<<std::setfill(' ')<<std::setw(5)<<"Weight"<<endl;
	for( auto & num : components ){
		
		   switch(num->Type()){
			case 1: cout<<*((Arm*)(num));
				    break;
			case 2: 
				    cout<<*((Torso*)(num));
				    break;
			case 3: 
				    cout<<*((Locomotor*)(num));
				    break;
			case 4: 
				    cout<<*((Head*)(num));
				    break;
			case 5: 
				    cout<<*((Battery*)(num));
				    break;					
		}			 
	 } 
}
string shop::Print_Processed_Orders(){
	int i=0;
   string temp="(Index)	Order_Number	Date Of Order  SA Name	\n";
   for(auto &num: shop_processed_Orders){
	temp +='('+to_string(i)+')'+"\t"+to_string(num->Get_Order_Number())+"\t\t"+num->Get_Order_Date()+"\t"+num->Get_SAO_Name()+"\n";
      i++; 
    }
	return(temp);
}
string shop::Print_Unprocessed_Orders (){
	int i=0;
   string temp="(Index)	Order_Number	Date Of Order  \n";
   for(auto &num: shop_unprocessed_Orders){
	temp +='('+to_string(i)+')'+"\t"+to_string(num->Get_Order_Number())+"\t\t"+num->Get_Order_Date()+"\n";
      i++; 
    }
	return(temp);
}
void shop::Print_SA_list(){
		cout<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Month Salary"
		<<std::left<<std::setfill(' ')<<std::setw(25)<<"Number of Orders processed"<<endl;
        for( auto & num : Sales_Associate_of_Shop ){
			cout<<*((SA*)(num));
		}
}
/****************** SAVE ********************/
void shop::save_Robot_Models(){
	char c='*';
	ofstream ShopFile ("Robot_Models_Saved.txt");
	for( auto & num : Models ){
      	ShopFile<<c<<endl;
		num->save(ShopFile);
	}
	
	ShopFile.close();}
void shop::save_Robot_Components(){
	ofstream shopFile ("Robot_Components_Saved.txt");
	for( auto & num : components ){
		   switch(num->Type()){
			case 1: shopFile<<num->Type()<<endl;
			        num->save(shopFile);
				    break;
			case 2: shopFile<<num->Type()<<endl;
				    num->save(shopFile);				
				    break;
			case 3: shopFile<<num->Type()<<endl;
				    num->save(shopFile);
				    break;
			case 4: shopFile<<num->Type()<<endl;
				    num->save(shopFile);
				    break;
			case 5: shopFile<<num->Type()<<endl;
				    num->save(shopFile);
				    break;					
		}			 
	 } 
	shopFile.close();
}
void shop::save_List_SA(){
	char c='#';	
	ofstream file2("SA.txt");
		for( auto & num : Sales_Associate_of_Shop ){
      	file2<<c<<endl;
		num->save(file2);
		}
	file2.close();
}
void shop::save_PHB_info(){
	
}
void shop::save_PM_info(){
	
}
/****************** READ ********************/
void shop::Read_Robot_Components(){
	int type = 0;
	ifstream file2("Robot_Components_Saved.txt");
	if(file2.is_open()){
		while(!file2.eof()){
			
			type=get_int(file2);
			switch(type) {
				case 1: 
                        components.push_back(new Arm(file2));
					    break;
				case 2: 
                        components.push_back(new Torso(file2));				
					    break;
				case 3: 
                        components.push_back(new Locomotor(file2));
					    break;
				case 4: 
                        components.push_back(new Head(file2));
					    break;
				case 5: 
                        components.push_back(new Battery(file2));	
					    break;
							}
		}
		file2.close();
	}
}
void shop::Read_Robot_Models(){
	char t;
	ifstream file2("Robot_Models_Saved.txt");
	if(file2.is_open()){
		while(!file2.eof()){
			t=get_char(file2);
			if(t=='*'){
			Models.push_back(new Robot_model(file2));}
			}
		file2.close();
	}
}
void shop::Read_SA_List(){
	char t;
	ifstream file2("SA.txt");
	if(file2.is_open()){
		while(!file2.eof()){
			t=get_char(file2);
			if(t=='#'){
			Sales_Associate_of_Shop.push_back(new SA(file2));}
			}
		file2.close();
	}
	
}
void shop::Read_PHB_info(){
	
}
void shop::Read_PM_info(){
	
}
/****************** PHB AND SA ******************/
void  shop::Give_Deny_Raise_SA(int index, int yes_No){
   if(yes_No ==1){
	     int X = Sales_Associate_of_Shop[index]->number_of_processed_orders();
	     double Raise_by = X * 10; /* 10 dollars per Processed Order */
	     Sales_Associate_of_Shop[index]->Give_Raise(Raise_by);
   }
   else
   {
	    Sales_Associate_of_Shop[index]->Give_Raise(0.0);
   }
}
/****************** Process Order ******************/
void shop::Process_Order(int index){
	  shop_processed_Orders.push_back(shop_unprocessed_Orders[index]);
	  shop_unprocessed_Orders.erase(shop_unprocessed_Orders.begin() + index);
}
Order* shop::Get_Unprocessed_Order(int index){
    return(shop_unprocessed_Orders[index]);
}
/****************** Destructor *****************/
shop::~shop(){
}
/****************** Adding Components to Model *****************/
void shop::model_add_component(int model_index,int component_index){
    Robot_Part * temp = components[component_index];
	int type = temp->Type();
	Arm * A;
	Torso *T;
	Locomotor * L;
	Head * H ;
	Battery * B;
	bool can_Add ;
	switch(type){
		case 1:
			   A= (Arm*)(temp);
			   can_Add=Models[model_index]->add_Arm((*(A)));
		//	cout<<" Can ADD ARM : "<<can_Add<<endl;
			   break;
		case 2:
			   T = (Torso*)(temp);
			  can_Add= Models[model_index]->add_Torso((*(T)));
		//	cout<<" Can ADD Torso : "<<can_Add<<endl;
			   break;
		case 3:
			  L =(Locomotor*)(temp);
			   can_Add=Models[model_index]->add_Locomotor((*(L)));
		//	cout<<" Can ADD Loco : "<<can_Add<<endl;
			   break;
		case 4:
			  H=(Head*)(temp);
			   can_Add=Models[model_index]->add_Head((*(H)));
		//	cout<<" Can ADD Head : "<<can_Add<<endl;
			   break;
		case 5:
			   B=(Battery*)(temp);
			   Models[model_index]->add_Battery((*(B)));
         //   cout<<"Can ADD battery \n";
			   break;
	}
		
}
/****************** Log in of Customers and SA ******************/
int shop::check_SA(string name, string pass){
	int i=0;
	for(auto & num : Sales_Associate_of_Shop){
	   if((num->Get_SA_Name())==name){
		  if(num->check_SA_Name_Pass(name,pass)){
			 return(i);//return index of SA
		  }//end_if_2
		  else{
			return(-1)  ;//pass word is wrong
		  }
	   }//end_if_1
	i++;
	}//end_for
	return(-2);//SA does not exist 
}
SA* shop::login (int index){
	return(Sales_Associate_of_Shop[index]);
}
/***************** SA list of processed Orders ********************/
string shop::SA_Processed_Orders(string name){
	string temp="Order Number	Order Date		Customer Name		Quantity\n";
	for(auto& num : shop_processed_Orders){
		if((num->Get_SAO_Name()) == name){
			temp+="\t"+to_string(num->Get_Order_Number())+"\t\t"+num->Get_Order_Date()+"\t\t"+num->Get_Customer_name()+"\t\t\t"+to_string(num->Get_Quantity())+'\n';
		}//end_if	
		}//end_for
	return temp;
}
string shop::List_Of_SA( ){
  string temp="(index)		NAME		Number of Orders Processed \n";
	int i=0;
	for(auto& num : Sales_Associate_of_Shop){
		temp+=to_string(i)+"\t\t"+num->Get_SA_Name()+"\t\t"+to_string(num->number_of_processed_orders())+"\n";
	i++;
	}
	return(temp);
}
string shop::list_components(int Type){
	int i=0;
	string temp;
		switch(Type){
		case 1: temp+="(Index)	Name	Number	Cost	weight	Arm Power	\n";  
				for(auto &num: components){
					if((num->Type())==Type){
temp+='('+to_string(i)+')'+"\t"+num->get_part_name()+"\t"+num->get_part_number()+"\t"+to_string(num->get_cost())+"\t";
temp+=to_string(num->get_weight())+"\t"+to_string(num->get_max_power_Arm())+"\nDesciption : "+num->get_part_description()+'\n';
					}
					i++;
				}
			   break;
		case 2:temp+="(Index)	Name	Number	Cost	weight	max_#_arms		battery_compartments\n";  
				for(auto &num: components){
					if((num->Type())==Type){
temp+='('+to_string(i)+')'+"\t"+num->get_part_name()+"\t"+num->get_part_number()+"\t"+to_string(num->get_cost())+"\t";
temp+=to_string(num->get_weight())+"\t"+to_string(num->get_max_arms())+"\t\t"+to_string(num->get_battery_compartments())+"\nDesciption : "+num->get_part_description()+'\n';
					}
					i++;
				}
			   break;
		case 3:temp+="(Index)	Name	Number	Cost	weight	max speed		max power\n";  
				for(auto &num: components){
					if((num->Type())==Type){
temp+='('+to_string(i)+')'+"\t"+num->get_part_name()+"\t"+num->get_part_number()+"\t"+to_string(num->get_cost())+"\t";
temp+=to_string(num->get_weight())+"\t"+to_string(num->get_max_speed())+"\t\t"+to_string(num->get_max_power())+"\nDesciption : "+num->get_part_description()+'\n';
					}
					i++;
				}
			   break;
		case 4:temp+="(Index)	Name	Number	Cost	weight	Head Power	\n";  
				for(auto &num: components){
					if((num->Type())==Type){
temp+='('+to_string(i)+')'+"\t"+num->get_part_name()+"\t"+num->get_part_number()+"\t"+to_string(num->get_cost())+"\t";
temp+=to_string(num->get_weight())+"\t"+to_string(num->Getpower())+"\nDesciption : "+num->get_part_description()+'\n';
					}
					i++;
				}
			  break;
		case 5:temp+="(Index)	Name	Number	Cost	weight	available power		max energy\n";  
				for(auto &num: components){
					if((num->Type())==Type){
temp+='('+to_string(i)+')'+"\t"+num->get_part_name()+"\t"+num->get_part_number()+"\t"+to_string(num->get_cost())+"\t";
temp+=to_string(num->get_weight())+"\t"+to_string(num->get_power())+"\t\t"+to_string(num->get_max_energy())+"\nDesciption : "+num->get_part_description()+'\n';
					}
					i++;
				}
			   break;	
			
	}
	return temp;
}











