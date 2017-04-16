#ifndef _UTILITY
#define _UTILITY 2017
#include <string>
#include <iostream>
using namespace std;
// /////////////////////////////////////////
// F I L E   I / O
// /////////////////////////////////////////

//
// Return any string from the file, including a simple \n
//
string get_string(istream& ist) {
  string result = "";
  getline(ist, result);
  return result;
}

//
// Skip all characters in the input buffer up to and including the next newline
// For use after a input stream operation, to clear invalid text and the newline
//
void skip(istream& ist) {
  if (ist.fail()) 
    ist.clear();
  ist.ignore(INT_MAX, '\n');  
}

//
// Return any valid integer from the file
// 
int get_int(istream& ist) {
  int result = 0;
  ist >> result;
  skip(ist);
  return result;
}

//
// Return any valid double from the file
//
double get_double(istream& ist) {
  double result = 0.0;
  ist >> result;
  skip(ist);
  return result;
}

#endif
