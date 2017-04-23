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
       if(state==Order_State::Packeged)
		   return("Packeged");
	   if(state==Order_State::Paid)
		   return("Paid");
	   if(state==Order_State::shipped)
		   return("shipped");
	   if(state==Order_State::canceled)
		   return("canceled");	  
}
Order_State read_state( string state){
	if(state == "pending")
		return (Order_State::pending);
	if(state == "Billed")
		return (Order_State::Billed);
	if(state == "Packeged")
		return (Order_State::Packeged);
	if(state == "Paid")
		return (Order_State::Paid);
	if(state == "shipped")
		return (Order_State::shipped);
	if(state == "canceled")
		return (Order_State::canceled);
	else
		return(Order_State::pending);
	
}