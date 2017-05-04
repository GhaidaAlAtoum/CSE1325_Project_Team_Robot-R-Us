#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <sstream>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Int_Input.H>
#include "shop.h"
#include "customer.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "customer_menu.h"
using namespace std;
Fl_Color Glob_color = fl_rgb_color(205, 232, 255);
/****************************** General Functions ******************************/
string Customer_gui::get_hello_text(){
    std::ostringstream ss;
		 ss<<std::left<<"\t\t"<<temp_customer->Get_name()<<endl
		  <<std::left<<"\t Wlecome to Robot'R'Us"<<endl
		  <<std::left<<"* View models and Make an Order \n press \"Make an Order\" "<<endl
		  <<std::left<<"* View Your Oders \" View Orders \" "<<endl
	      <<std::left<<"* Change Nam e Or Password \n";
	return ss.str();
}	
/****************************** Main Customer Window ******************************/
      Customer_gui::Customer_gui(customer* temp,int model){  	
	temp_customer=temp;
	number_of_models = model;
	  Main_CU_win();
      }
     void Customer_gui::Main_CU_win(){
		 
	string name = "Customer ";
	const char * cstr = name.c_str();
	string hello = this->get_hello_text();
	const char * hello_cstr = hello.c_str();
	
	CU_menu_win = new Fl_Window(500,620,cstr);
	CU_menu_win->color(Glob_color);
	CU_menu_win->begin();
	CU_menu_win->callback(window_callback,this);
	CU_order_button = new Fl_Button(50,270,200,70,"&Make an Order");  CU_order_button->color(FL_WHITE);
	CU_order_button->callback(CU_order_button_cb,this);
		
	CU_View_order = new Fl_Button(50,360,200,70,"&View Orders");   CU_View_order->color(FL_WHITE);
	CU_View_order->callback(CU_view_order_cb,this);
	
	CU_change_NP = new Fl_Button(50,450,200,70,"&Change Name or Password"); CU_change_NP->color(FL_WHITE);
	CU_change_NP->callback(CU_change_NP_cb,this);
	
	CU_menu_back_button = new Fl_Button(50,540,100,70,"&LogOut");   CU_menu_back_button->color(FL_WHITE);
	CU_menu_back_button->callback(CU_log_Out_cb,this);
	
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();	
    Fl_Text_Display *disp = new Fl_Text_Display(50, 50,400 ,200,0);	
	disp->buffer(buff); disp->textfont(FL_BOLD_ITALIC ); disp->textsize(15);
	buff->text(hello_cstr);
			CU_menu_win->resizable(CU_menu_win);
	CU_menu_win->end();	
	CU_menu_win->show();
		 
	 }
	 /* ---------------------- Open Order Menu  callback-------------------- */
	 void Customer_gui::CU_order_button_cb(Fl_Widget* w, void* v){
		 ((Customer_gui*)v)->CU_order_button_cb_i();
	 }
     void Customer_gui::CU_order_button_cb_i(){
		 cout << "Make an Order" << endl;
	     CU_menu_win->hide();
	     CU_order_menu_func();
	 }
 	 /* ---------------------- view Customer Orders callback -------------------- */
	 void Customer_gui::CU_view_order_cb(Fl_Widget* w, void* v){
		  ((Customer_gui*)v)->CU_view_order_cb_i();
	 }
     void Customer_gui::CU_view_order_cb_i(){
		 cout<<"View Orders"<<endl;
		 CU_menu_win->hide();
		  CU_View_Orders();
	 }
	 /* ---------------------- Change Customer Name and Password callback -------------------- */
	 void Customer_gui::CU_change_NP_cb(Fl_Widget* w, void* v){
		  ((Customer_gui*)v)->CU_change_NP_cb_i();
	 }
     void Customer_gui::CU_change_NP_cb_i(){
		 cout<<"Change Name and Password\n";
		 CU_menu_win->hide();
		 change_N_P();
	 }
	 /* ----------------------  Customer Logout callback -------------------- */
	 void Customer_gui::CU_log_Out_cb(Fl_Widget* w, void* v){
		  ((Customer_gui*)v)->CU_log_Out_cb_i();
	 }
     void Customer_gui::CU_log_Out_cb_i(){
		switch(fl_choice(" Do You Want To Log Out  ?","&No","&Yes",0))
		   {
		case 1:	
	         shop::save_all();
		 CU_menu_win->hide();
				   shop::show_Menu(1,0);
	         open =0;
			break;
		case 0: 
			break;
	}
	 }
     void Customer_gui::window_callback(Fl_Widget* w, void* v){
        ((Customer_gui*)v)->window_callback_i();
}
     void Customer_gui::window_callback_i(){	
		switch(fl_choice(" Do You Want To Log Out  ?","&No","&Yes",0))
		   {
		case 1:	
	          shop::save_all();
				    cout<<"Log_Out\n";
				   CU_menu_win->hide();
				    shop::show_Menu(1,0);
	         open =0;
			break;
		case 0: 
			break;
	}
}
	/**************************** Change Name and Password *************************/
      void change_np_callback(Fl_Widget* w,void * v){ 
		  if(((Customer_gui*)v)->name_pass == 0){
			 ((Customer_gui*)v)->temp_customer->set_Name((string)(((Customer_gui*)v)->string_In->value()));
		  }
		  else{
			  ((Customer_gui*)v)->temp_customer->set_pass((string)(((Customer_gui*)v)->string_In->value()));
		  }
		   ((Customer_gui*)v)->NP_win->hide();
		  ((Customer_gui*)v)->Main_CU_win();
	  }
	  void Customer_gui::change_N_P(){
		 
		switch(fl_choice("Name or Password?","&Name","&Password",0)){
		 case 0:
				 name_pass=0;
				 break;
		 case 1:
		         name_pass=1;
				 break;
		 }
		 NP_win = new Fl_Window(200,200,"Change Name/Password ");
		 NP_win->begin(); NP_win->color(Glob_color);
		 string_In= new Fl_Input(50,50,100,50,"New"); string_In->color(FL_WHITE);
		 change = new Fl_Button(50,130,70,50,"Change"); change->color(FL_WHITE); change->callback(change_np_callback,this);
		 NP_win->end();
		 NP_win->show();
	   }
/************************ View Models and Creat an Order **********************************/
    /* ---------------------- Show Picture Callback -------------------- */
	    void showPic_callback(Fl_Widget* w,void * v){
	         int j=0;
	         for(j=0;j<((Customer_gui*)v)->show_pic.size();j++){
	               if(((Customer_gui*)v)->show_pic[j] == (Fl_Button*) w){
	                    cout<<" Found \n";
		                break;
	                          }
	                       }
                  cout<<" Call back "<<j<<endl; 
            }
	/* ---------------------- Order Model Callback -------------------- */
	   void order_model_callback(Fl_Widget* w, void * v){
	        switch(fl_choice(" Do You Want To Order ?","&No","&Yes",0)){
		 case 1:{
				 int j=0;
	             for(j=0;j<((Customer_gui*)v)->order_model.size();j++){
	             if(((Customer_gui*)v)->order_model[j] == (Fl_Button*) w){
		          break;}//end_if
	                 }//end_for
                ((Customer_gui*)v)->quant_win(); 
				while(((Customer_gui*)v)->Quan->shown())
                { Fl::wait(); }
				cout<<"back\n\n";
				((Customer_gui*)v)->temp_customer->push_Order(j,((Customer_gui*)v)->Quantity);
			      break;}
		 case 0:
			      break;
	      } 
	 }
       void CU_menu_back_button_cb(Fl_Widget* w , void *v) {
              ((Customer_gui*)v)->win->hide();
		      ((Customer_gui*)v)->Boxes.clear();
			  ((Customer_gui*)v)->order_model.clear();
		      ((Customer_gui*)v)->order_model.clear();  
		      ((Customer_gui*)v)->Main_CU_win();
             }		
     /* ---------------------- Creating Order Menu  -------------------- */
       void Customer_gui::CU_order_menu_func() {
         int x_pos =20;
	     int y_pos =50;
	     int j=0;
	     int limmit = (this->number_of_models);
		 long i=0;
	         win = new Fl_Window(800,700,"Shop Models"); win->color(Glob_color); win->begin(); 
		     Back = new Fl_Button(50,630,70,60,"&Back");Back->color(FL_WHITE); Back->callback(CU_menu_back_button_cb,this);
	         scroll = new Fl_Scroll(0,20,800,600); scroll->color(Glob_color);scroll->begin();
  	         Fl_Text_Buffer *buff = new Fl_Text_Buffer();

	     cout<<"limit = "<<limmit<<endl;
	         for (j=0;j<limmit;j++)
	           {
		          Boxes.push_back(new Fl_Text_Display(20,y_pos,600,200,0));
		          Boxes[j]->buffer(buff); 
		          buff->text((shop::Print_Models_by_index(j)).c_str());									
		          show_pic.push_back(new Fl_Button((x_pos+10+600),y_pos,80,70,"Show Pic."));
		          order_model.push_back(new Fl_Button((x_pos+10+600),y_pos+80,80,70,"Order"));
		          y_pos+=210;
	          }
	      
	       for(auto & num : Boxes){
	         	num->box(FL_BORDER_BOX); num->color(FL_WHITE);
	            }
        
	       for(auto & num : show_pic){
		       num->callback(showPic_callback,this); num->color(FL_WHITE);
		       i++;
		      }
    	      i=0;
		      for(auto & num : order_model){
		      	num->callback(order_model_callback,this); num->color(FL_WHITE);
		      i++;
		      }
		      scroll->show();
		      scroll->end();
		      win->resizable(scroll);
		      win->end();
		      win->show();	
                       }						   			   					
     /* ---------------------- Quantity Menu -------------------- */
       void Customer_gui::quant_win(){
	            Quan = new Fl_Window(200,150,"Quantity"); Quan->color(Glob_color);
				Quan->begin();
				num = new Fl_Int_Input(100,20,50,50,"Quantity");//child0
				add = new Fl_Button(100,80,50,50,"&Add");add->color(FL_WHITE);//child1
				add->callback(add_callback,this);
				Quan->end();
				Quan->show();
       }
     /* ---------------------- Add Callback -------------------- */
   	   void Customer_gui::add_callback(Fl_Widget* w , void *v){
          ((Customer_gui*)v)->add_callback_i();
	    }
  	   void Customer_gui::add_callback_i(){	
	     Quantity = stoi(((string) num->value()));   	     
         cout<<"ORDER Done"<<Quantity<<endl;
		  Quan->hide();
		}

/********************************** View Orders **********************************/
       /* ---------------------- Pay For Order -------------------- */
       void pay_callback(Fl_Widget* w,void * v){
	       switch(fl_choice(" Do You Want To Pay ?","&No","&Yes",0)){
		    case 1:{
				 int j=0;
	             for(j=0;j<((Customer_gui*)v)->Pay.size();j++){
	             if(((Customer_gui*)v)->Pay[j] == (Fl_Button*) w){
	            if(!( ((Customer_gui*)v)->temp_customer->Pay_Order(j))){
					fl_message (" Cant Pay either already paid or not billed yet ");
				}
		          break;
	                 }//end_if
	                 }//end_for
        cout<<" Order Number  "<<j<<endl;
			      break;}
		 case 0:
			      break;
	             } 
            }
	   /* ---------------------- Order Model Callback -------------------- */
	   void cancel_order_callback(Fl_Widget* w, void * v){
	        switch(fl_choice(" Do You Want To Cancel ?","&No","&Yes",0)){
		 case 1:{
				 int j=0;
	             for(j=0;j<((Customer_gui*)v)->Cancel.size();j++){
	             if(((Customer_gui*)v)->Cancel[j] == (Fl_Button*) w){
                 if(!(((Customer_gui*)v)->temp_customer->cancel_order(j))){
					fl_message (" Cant Cancel if Paid , packaged or shipped "); 
				 }
		          break;
	                 }//end_if
	                 }//end_for
			      break;}
		 case 0:
			      break;
	      } 
	 } 
	   void bill_callback(Fl_Widget* w, void * v){
	        switch(fl_choice(" Do You Want To Pay ?","&No","&Yes",0)){
		 case 1:{
				 int j=0;
	             for(j=0;j<((Customer_gui*)v)->View_Bill.size();j++){
	             if(((Customer_gui*)v)->View_Bill[j] == (Fl_Button*) w){
	             cout<<" O Fou \n";
		          break;
	                 }//end_if
	                 }//end_for
        cout<<" Order Number  "<<j<<endl;
			      break;}
		 case 0:
			      break;
	      } 
	 } 
       void Back_cb(Fl_Widget* w , void *v) {
              ((Customer_gui*)v)->Order_win->hide(); ((Customer_gui*)v)->Details.clear();
		      ((Customer_gui*)v)->Pay.clear(); 
		      ((Customer_gui*)v)->Cancel.clear(); 
		      ((Customer_gui*)v)->View_Bill.clear(); 
 ((Customer_gui*)v)->Main_CU_win();             }		
       /* ---------------------- View Order Menu  -------------------- */
       void Customer_gui::CU_View_Orders() {
         int x_pos =20;
	     int y_pos =50;
	     int j=0;
	     int limmit = (temp_customer->Get_Number_of_orders());
		 long i=0;
	         Order_win = new Fl_Window(800,700,"Customer Orders"); Order_win->color(Glob_color); Order_win->begin(); 
		     Order_Back = new Fl_Button(50,630,70,60,"&Back");Order_Back->color(FL_WHITE); Order_Back->callback(Back_cb,this);
	         Order_scroll = new Fl_Scroll(0,20,800,600); Order_scroll->color(Glob_color);Order_scroll->begin();
  	         Fl_Text_Buffer *buff = new Fl_Text_Buffer();

	     cout<<"limit orders = "<<limmit<<endl;
	         for (j=0;j<limmit;j++)
	           {
		          Details.push_back(new Fl_Text_Display(20,y_pos,600,200,0));
		          Details[j]->buffer(buff); 
		          buff->text("Bill");
		         buff->text((temp_customer->view_Orders(j)).c_str());									
		         Pay.push_back(new Fl_Button((x_pos+10+600),y_pos,80,40,"Pay"));
		         Cancel.push_back(new Fl_Button((x_pos+10+600),y_pos+50,80,40,"Cancel"));
				 View_Bill.push_back(new Fl_Button((x_pos+10+600),y_pos+100,80,40,"Bill"));
		         y_pos+=210;
	           }
	      
	       for(auto & num : Details){ num->box(FL_BORDER_BOX); num->color(FL_WHITE); }
        
	       for(auto & num : Pay){ num->callback(pay_callback,this); num->color(FL_WHITE);}
    	
		   for(auto & num : Cancel){ num->callback(cancel_order_callback,this); num->color(FL_WHITE);}
		   
		   for(auto & num : View_Bill){ num->callback(bill_callback,this); num->color(FL_WHITE);}
		      Order_scroll->show();
		      Order_scroll->end();
		      Order_win->resizable(Order_scroll);
		      Order_win->end();
		      Order_win->show();	
                       }	
	   	   
								   
	





















								   