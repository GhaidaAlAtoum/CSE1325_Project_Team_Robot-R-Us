#ifndef USE_H
#define USE_H
#include <string>
#include <climits>
#include <iostream>
using namespace std;
// /////////////////////////////////////////
// F I L E   I / O
// /////////////////////////////////////////

//
// Return any string from the file, including a simple \n
//
string get_string(istream& ist) ;

//
// Skip all characters in the input buffer up to and including the next newline
// For use after a input stream operation, to clear invalid text and the newline
//
void skip(istream& ist);

//
// Return any valid integer from the file
// 
int get_int(istream& ist);

//
// Return any valid double from the file
//
double get_double(istream& ist) ;
char get_char(istream& ist) ;

enum class Order_State{
	pending,//1
 	 Billed,//2
	 Paid,//3
	 canceled,//4
	paid_Packeged,//5
	paid_shipped,//6
};
string print_state(Order_State);
Order_State read_state( string state);
#endif
