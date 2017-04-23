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