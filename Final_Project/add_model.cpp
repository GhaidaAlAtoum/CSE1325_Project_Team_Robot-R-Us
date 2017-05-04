#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_ask.H>
#include <string>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Int_Input.H>
#include "Controller.h"
#include <iostream>
using namespace std;

int arm_counter=0;
int torso_counter=0;
int loco_counter=0;
int head_counter=0;

void AM_ARM_CB(Fl_Widget * w, void *v){
	cout << "ARM CB called" << endl;
	   if(arm_counter==2){
	      fl_alert("Max Number of arms =2 ");
	   return;
                        }
   Fl_Choice * temp = (Fl_Choice*) w;
   Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
   string text="Arm Call Back "+std::to_string(temp->value())+"\n";
	char *s= new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
		arm_counter++;
}
void AM_TORSO_CB(Fl_Widget * w, void * v){
   if(torso_counter==1){
	      fl_alert("Max Number of torso =1 ");
	   return;
   }
   Fl_Choice * temp = (Fl_Choice*) w;
	  Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text ="Torso Call Back "+std::to_string(temp->value())+"\n";
	char *s = new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
    torso_counter++;
}
void AM_LOCO_CB(Fl_Widget * w, void *v ){
	   if(loco_counter==1){
	      fl_alert("Max Number of locomotor =1 ");
	   return;
   }
   Fl_Choice * temp = (Fl_Choice*) w;
	 Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text="Locomotor Call Back "+std::to_string(temp->value())+"\n";
	char *s = new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
	loco_counter++;
}
void AM_HEAD_CB(Fl_Widget * w, void * v){
   if(head_counter==2){
	      fl_alert("Max Number of head =1 ");
	   return;
   }
	   Fl_Choice * temp = (Fl_Choice*) w;
	 Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text="Head Call Back "+std::to_string(temp->value())+"\n";
char *s= new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
	head_counter++;
}
void AM_BATTERY_CB(Fl_Widget * w, void * v){

	   Fl_Choice * temp = (Fl_Choice*) w;
	 Fl_Text_Display *disp = (Fl_Text_Display *)v;
   Fl_Text_Buffer *buff = disp->buffer();
   buff->remove_selection();
	string text="Battery Call Back "+std::to_string(temp->value())+"\n";
char *s= new char[text.length()+1];
	strcpy(s,text.c_str());
	buff->text(s);
}

void Controller::AM_back_cb(Fl_Widget *w, void* v) {
	((Controller*)v)->AM_back_cb_i();	
}
void Controller::AM_back_cb_i() {
	AM_win->hide();
	PM_mainmenu_window->show();
}



void Controller::add_model_func() {
    AM_win = new Fl_Double_Window(800,500,"Input Choice");
    AM_win->begin(); 
	AM_name = new Fl_Input(100,20,200,50,"Model Name");//child(0)
	AM_number = new Fl_Input(500,20,200,50,"Model number");//child(1)
	AM_menu= new Fl_Choice(200,100,400,50,"&Shop Components");//child(2)
	AM_back = new Fl_Button(100,440,100,50,"Back");//child(3)
	AM_back->callback(AM_back_cb, this);
	
	AM_index = new Fl_Int_Input(250,440,150,50,"Index");//child(4)
	AM_ADD = new Fl_Button(450,440,100,50,"Add");//child(5)
	AM_show = new Fl_Button(600, 440,100,50,"show");//child(6)
	AM_disp = new Fl_Text_Display(10,170,780,250, "Text");//child(7)
	AM_buff = new Fl_Text_Buffer();//child(8)
	AM_disp->buffer(AM_buff);
	AM_buff->text("Test \n Test");
	AM_menu->textfont(11); 	AM_menu->textcolor(136);
	AM_menu->add("&Arm",0,AM_ARM_CB,AM_disp);
	AM_menu->add("&Torso",0,AM_TORSO_CB,AM_disp);
	AM_menu->add("&Locomotor",0,AM_LOCO_CB,AM_disp);
	AM_menu->add("&Head",0, AM_HEAD_CB,AM_disp);
	AM_menu->add("&Battery",0,AM_BATTERY_CB,AM_disp);
  AM_win->end();
  AM_win->show();

}



