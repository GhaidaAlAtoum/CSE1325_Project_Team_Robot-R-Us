#include "Controller.h" 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "mainG.h"
#include <FL/fl_ask.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "shop.h"
using namespace std;

////////////////////////////////////
// Main Menu Functions, callbacks //
////////////////////////////////////
void window_callback(Fl_Widget* w, void*){
	switch(fl_choice(" Do You Want To Exit SHOP  ?","&No","&Yes",0))
		   {
		case 1:	
				   cout<<"first save\n";
	  shop::save_all();
				   cout<< "return\n";
	  ((Fl_Window*)w)->hide();
			
			break;
		case 0: 
			break;
	}
}
void main_b1_cb(Fl_Widget* w, void* v) {
	cout << "Product Manager" << endl;
	Fl_Button *b =(Fl_Button*)w;
	b->parent()->hide();
	shop::show_Menu(2,1);
}

void main_b2_cb(Fl_Widget* w, void* v) {
	cout << "Sales A" << endl;
	Fl_Button *b =(Fl_Button*)w;
	b->parent()->hide();
	shop::show_Menu(2,3);
}

void main_b3_cb(Fl_Widget* w, void* v) {
	cout << "Customer " << endl;
	Fl_Button *b =(Fl_Button*)w;
	b->parent()->hide();
	shop::show_Menu(2,4);
}

void main_b4_cb(Fl_Widget* w, void* v) {
	//((Controller*)v)->main_b4_cb_i();
	cout << "Callback" << endl;
}
// We gotta put the right stuff in the callbacks.. otherwise done		
main_menu::main_menu() 
{       fl_register_images();
		main_window = new Fl_Window(500,500, "Robots'R'us");
	    main_window->callback(window_callback);
	    main_window->begin();
	    main_background = new Fl_Box(0,0,500,500);
	    jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	    main_background->image(*jpg);
        Title_box = new Fl_Box(50,10,400,164);
	    jpg2 = new Fl_JPEG_Image("backwhite.jpg");
	    Title_box->image(jpg2);
   
	  	main_button1 = new Fl_Button(150,200,200,50,"Product Manager");
        main_button1->labelsize(20);
		main_button1->callback(main_b1_cb, this);
        main_button1->color(FL_WHITE);
	
		main_button2 = new Fl_Button(150,270,200,50,"Sales Associate");
		main_button2->callback(main_b2_cb, this);
	    main_button2->labelsize(20);
        main_button2->color(FL_WHITE); 
 
		main_button3 = new Fl_Button(150,340,200,50,"Customer");
		main_button3->callback(main_b3_cb, this);
	    main_button3->labelsize(20);
        main_button3->color(FL_WHITE);
 
		main_button4 = new Fl_Button(150,410,200,50,"Boss");
		main_button4->callback(main_b4_cb, this);
		main_button4->labelsize(20);
        main_button4->color(FL_WHITE);
		main_window->end();
}

void main_menu::show_window() {main_window->show();}
void main_menu::hide_window() {main_window->hide();}