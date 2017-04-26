#include "USE.h"
#include <string>
#include <climits>
#include <iostream>
using namespace std;

string get_string(istream& ist) {
  string result = "";
  getline(ist, result);
  return result;
}
char get_char(istream& ist) {
  char result =' ';
   ist >> result;
  skip(ist);
	return result;
}
void skip(istream& ist) {
  if (ist.fail()) 
    ist.clear();
  ist.ignore(5, '\n');  
}

int get_int(istream& ist) {
  int result = 0;
  ist >> result;
  skip(ist);
  return result;
}

double get_double(istream& ist) {
  double result = 0.0;
  ist >> result;
  skip(ist);
  return result;
}
string print_state(Order_State state){
       if(state==Order_State::pending)
		   return("pending");
	   if(state==Order_State::Billed)
		   return("Billed");
	   if(state==Order_State::Paid)
		   return("Paid");
	   if(state==Order_State::canceled)
		   return("canceled");	  
	   if(state==Order_State::paid_Packeged)
		   return("paid_Packeged");
	   if(state==Order_State::paid_shipped)
		   return("paid_shipped");
}
Order_State read_state( string state){
	if(state == "pending")
		return (Order_State::pending);
	if(state == "Billed")
		return (Order_State::Billed);
	if(state == "Paid")
		return (Order_State::Paid);
	if(state == "canceled")
		return (Order_State::canceled);
	if(state == "paid_Packeged")
		return (Order_State::paid_Packeged);
	if(state == "paid_shipped")
		return (Order_State::paid_shipped);
	else
		return(Order_State::pending);
	
}