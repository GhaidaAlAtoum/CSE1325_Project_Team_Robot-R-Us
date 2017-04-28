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
#include <sstream>
#include "login.h"
#include "mainG.h"
using namespace std;
/****************** components ********************/
vector <Robot_Part*> shop::components;
/****************** Models ********************/
vector <Robot_model*> shop::Models;
/****************** Customers ********************/
vector <customer*> shop::shop_Customers;
/****************** Product Manager &  Boss ********************/
Product_Manager shop::shop_Product_Manager = Product_Manager::get_Instance();
PHB shop::boss = PHB::get_Instance_PHB();
/****************** Orders ********************/
vector <Order*>  shop::shop_orders ;
int shop::num_orders=0;
/****************** Sales Associates ********************/
vector <SA*> shop::Sales_Associate_of_Shop;
/****************** Main Window ********************/
main_menu shop::Main_Gui;
/****************** Product Manager GUI ********************/
 
/****************** Boss GUI ********************/
	 
/****************** Customer GUI ********************/
//customer_gui shop::customer_shop_gui; 
/****************** SA GUI ********************/
void shop::show_Menu(int Type,int log){
		
		  switch(Type){
		       case 1: {// Main Menu 
			         Main_Gui.show_window();
			          break;}
		       case 2: {Log_In_Gui LogIn(log);
			         LogIn.show_log();
			          break;}
			   case 3: {//Product Manager
			   
			          break;}
			   case 4:{ //Boss
			   
			          break;}
			   case 5: {//Customer
			   
			          break;}
			   case 6: {//SA
			   
			          break;}
		       default: // SHOW THE MAIN ALSO 
			   
			          break;
 		  }
	}
/****************** Shop Get Instance  ********************/
shop& shop::Instance_shop( ){
	static shop instance;
           return instance;
}
/****************** ADD ********************/
void shop::add_PM(Product_Manager & temp){
 shop_Product_Manager=temp;	
}
void shop::add_boss(PHB & temp){
 	boss=temp;
}
void shop::add_Customer(customer * temp){
  	shop_Customers.push_back(temp);
}
void shop::add_component(Robot_Part * temp){
	   	components.push_back(temp);
}
void shop::add_Model(Robot_model* temp){
    	Models.push_back(temp);
}
Order* shop::add_Order(int model_index,int Quantity,string Name){
	 int num = num_orders;
	 Robot_model temp_model= *(Models[model_index]);
	 Order *temp =new Order(num,temp_model,Name);
	 temp->set_Quantity(Quantity);
     shop_orders.push_back(temp);
	 num_orders++;
	 return((temp));
}
void shop::add_SA(SA * temp){
	for(auto & num : Sales_Associate_of_Shop){
		if((num->Get_SA_Name())==(temp->Get_SA_Name())){
		 cout<<" ERROR THIS NAME EXIST IN THE SA LIST  WILL NOT BE ADDED\n";
			return;
		}
	}
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
void shop::remove_order(int number){
    shop_orders.erase(shop_orders.begin()+number);
}
/****************** PRINT********************/
string shop::Print_Catalog_Models(){
	std::ostringstream ss;		
	ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(10)<<"Price"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Weight"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Battery Life"
		<<std::left<<std::setfill(' ')<<std::setw(10)<<"Max Speed"<<endl;
	for( auto & num : Models ){
	    ss<< *((Robot_model*)(num));
	}
	return ss.str();
}
string shop::Print_Catalog_Components(){
	std::ostringstream ss;
	ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(5)<<"Cost"
		<<std::left<<std::setfill(' ')<<std::setw(5)<<"Weight"<<endl;
	for( auto & num : components ){
		
		   switch(num->Type()){
			case 1: ss<<*((Arm*)(num));
				    break;
			case 2: 
				    ss<<*((Torso*)(num));
				    break;
			case 3: 
				    ss<<*((Locomotor*)(num));
				    break;
			case 4: 
				    ss<<*((Head*)(num));
				    break;
			case 5: 
				    ss<<*((Battery*)(num));
				    break;					
		}			 
	 }
	return ss.str();
}
string shop::Print_all_Orders(){
	std::ostringstream ss;
		ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Quantity"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Date"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Model Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Customer"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Status"<<endl;
	for(auto & num: shop_orders){
	  	  ss << *((Order*)(num));
	}
		return ss.str();
}
string shop::Print_Unprocessed_Orders (){
 std::ostringstream ss;
		ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Quantity"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Date"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Model Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Customer"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Status"<<endl;
	
	for(auto & num: shop_orders){
		Order_State temp = num->Get_Order_status();
		if( temp == (Order_State::pending)){
	  	ss << *((Order*)(num));
		}
	}
		return ss.str();
}
string shop::Print_SA_list(){
	std::ostringstream ss;	
	ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Month Salary"
		<<std::left<<std::setfill(' ')<<std::setw(25)<<"Number of Orders processed"<<endl;
        for( auto & num : Sales_Associate_of_Shop ){
			ss<<*((SA*)(num));
		}
	return ss.str();
}
string shop::Print_Profit_Margin( ){
	    string temp;
		std::ostringstream ss;	
	    ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(10)<<"Price"
		<<std::left<<std::setfill(' ')<<std::setw(10)<<"Profit Margin"<<endl;
	   for( auto & num : Models ){
	   temp += num->Profit_margin();
	}
	return(ss.str()+temp);
}
string shop::Print_Orders_By_SA(string name){
	 string temp;
	 std::ostringstream ss;
	 ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Quantity"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Date"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Model Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Customer"
		<<std::left<<std::setfill(' ')<<std::setw(15)<<"Status"<<endl;
	 for(auto & num: shop_orders){
		 if(num->Get_SAO_Name()==name){
	 if((num->Get_Order_status()) == Order_State::Paid || (num->Get_Order_status()) == Order_State::paid_Packeged ){   
			 ss << *((Order*)(num)); 
		 }
	 }
	 }
			return ss.str();
}
/****************** SAVE ********************/
void shop::save_Robot_Models(){
	cout<<" SAVE SAVE \n";
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
	char c ='%';
	ofstream file2("PHB.txt");
	file2<<c<<endl;
	boss.save(file2);
	file2.close();
}
void shop::save_PM_info(){
	char c ='@';
	ofstream file2("PM.txt");
	file2<<c<<endl;
	shop_Product_Manager.save(file2);
	file2.close();
}
void shop::save_orders(){
	char c ='!';
	ofstream ShopFile ("Orders.txt");
	for( auto & num : shop_orders ){
		ShopFile<<c<<endl;
		num->save(ShopFile);	
	}
	
	ShopFile.close();
}
void shop::save_Customers(){
     char c = '?';
	ofstream ShopFile ("customer.txt");
	for( auto & num : shop_Customers ){
		ShopFile<<c<<endl;
		num->save(ShopFile);	
	}
	
	ShopFile.close();
}
void shop::save_all(){
	shop::save_Customers();
	shop::save_Robot_Models();
shop::save_Robot_Components();
shop::save_List_SA();
shop::save_PHB_info();
shop::save_PM_info();
shop::save_orders();
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
	char t;
	ifstream file2("PHB.txt");
	if(file2.is_open()){
		t=get_char(file2);
			if(t=='%'){
				boss.read(file2);
			}
      file2.close();
	}
}
void shop::Read_PM_info(){
	char t;
	ifstream file2("PM.txt");
	if(file2.is_open()){
		t=get_char(file2);
			if(t=='@'){
				shop_Product_Manager.Read(file2);
			}
      file2.close();
	}
}
void shop::Read_Customers(){
		char t;
	ifstream file2("customer.txt");
	if(file2.is_open()){
		while(!file2.eof()){
			t=get_char(file2);
			if(t=='?'){
			shop_Customers.push_back(new customer(file2));}
			}
		file2.close();
	}
}
void shop::Read_orders(){
	char t;
	ifstream file2("Orders.txt");
	if(file2.is_open()){
		while(!file2.eof()){
			t=get_char(file2);
		if(t=='!'){
			shop_orders.push_back(new Order(file2));}
			}
		file2.close();
	}
	
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
Order* shop::Get_Unprocessed_Order(int index){
	for(auto&num : shop_orders){
	    if(num->Get_Order_Number() == index){
			return(num);
			
		}
	}
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
			   break;
		case 2:
			   T = (Torso*)(temp);
			  can_Add= Models[model_index]->add_Torso((*(T)));
			   break;
		case 3:
			  L =(Locomotor*)(temp);
			   can_Add=Models[model_index]->add_Locomotor((*(L)));
			   break;
		case 4:
			  H=(Head*)(temp);
			   can_Add=Models[model_index]->add_Head((*(H)));
			   break;
		case 5:
			   B=(Battery*)(temp);
			   Models[model_index]->add_Battery((*(B)));
			   break;
	}
		
}
/****************** Log in of Customers, SA, PM, BOSS ******************/
bool shop::check_PM(string name, string pass){
return(shop_Product_Manager.check_name_pass(name,pass));
}
Product_Manager& shop::login_PM(){
	return(shop_Product_Manager);
}
int shop::check_boss(string name, string pass){
	return( boss.check_PHB_Name_Pass(name,pass));
}
PHB& shop::login_boss(){
	return(boss);
}
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
int shop::check_customer(string email, string pass){
	int i=0;
	for(auto & num : shop_Customers){
	   if((num->Get_email())==email){
		  if(num->check_customer(email,pass)){
			 return(i);//return index of SA
		  }//end_if_2
		  else{
			return(-1)  ;//pass word is wrong
		  }
	   }//end_if_1
	i++;
	}//end_for
	return(-2);//customer does not exist 
}
customer* shop::login_customer(int index){
	return(shop_Customers[index]);
}
/***************** Print SA bu name ********************/
string shop::PRINT_SA_BY_NAME(string name){
   std::ostringstream ss;
	for(auto& num : Sales_Associate_of_Shop){
	    if((num->Get_SA_Name())==name){	
	      ss<<*((SA*)(num));
		}
	}
    return ss.str();
}
/***************** print componentss by type ********************/
string shop::list_components(int Type){
	std::ostringstream ss;
	ss<<std::left<<std::setfill(' ')<<std::setw(20)<<"Name"
		<<std::left<<std::setfill(' ')<<std::setw(20)<<"Number"
		<<std::left<<std::setfill(' ')<<std::setw(5)<<"Cost"
		<<std::left<<std::setfill(' ')<<std::setw(5)<<"Weight"<<endl;
		switch(Type){
		case 1:
				for(auto &num: components){
					if((num->Type())==Type){
						 ss<<*((Arm*)(num));
					}
				}
			   break;
		case 2:
				for(auto &num: components){
					if((num->Type())==Type){
						  ss<<*((Torso*)(num));
					}
				}
			   break;
		case 3:
				for(auto &num: components){
					if((num->Type())==Type){
						ss<<*((Locomotor*)(num));
					}
				}
			   break;
		case 4:
				for(auto &num: components){
					if((num->Type())==Type){
						ss<<*((Head*)(num));
					}
				}
			  break;
		case 5:
				for(auto &num: components){
					if((num->Type())==Type){
						ss<<*((Battery*)(num));
					}
				}
			   break;	
	}
      return ss.str();
}
/****************** Destructor *****************/
shop::~shop(){
}









