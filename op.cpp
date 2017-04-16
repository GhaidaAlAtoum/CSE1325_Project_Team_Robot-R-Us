#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
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
string get_string(istream& ist) {
  string result = "";
  getline(ist, result);
  return result;
}

class Ninja{
	private:
	int modelnum;
    string name;
	public:
	Ninja (int model, string n){
		modelnum = model;
		name=n;
	}
	Ninja (istream& input){
	   	modelnum=get_int(input);
		name=get_string(input);	
	}
	Ninja() {
		modelnum =0;
		name="NUN";
	}
	double weight;
	void attack(){cout << "ninja attack!" <<endl;}
	int Type(){
			return 1;
		}
	friend ostream& operator<<(ostream& ,Ninja& );
	void save(ostream& out){
	   out<<Type()<<endl;
	   out<<modelnum<<"\n";
	   out<<name<<endl;
	}
	
    };
 ostream& operator<<(ostream& output,Ninja& ninja){
	  output<<"Model Num "<<std::left<<std::setfill('*')<<std::setw(12)<<ninja.modelnum<< " Name "<<std::left<<std::setfill('#')<<std::setw(12)<< ninja.name;
	   return output;
	 
   }

int main() {
	string temp;
	vector <Ninja *> n;
	n.push_back(new Ninja(100,"dhGh"));
	n.push_back(new Ninja(500200,"Ba dsdggdfg"));
    ofstream ShopFile ("TEST.txt");
	for(auto & num : n){
	 cout<<(*num)<<endl;
	  num->save(	ShopFile);	
	}
    ShopFile.close();
	ifstream input("TEST.txt");
	vector <Ninja*> n2;
	if(input.is_open()){
		while(!input.eof()){
			if(get_int(input)==1){
				n2.push_back(new Ninja(input));
			}
		}
	}
	input.close();
	    ofstream file ("TEST.txt");
	for(auto & num : n2){
	 cout<<(*num)<<endl;
	  	
	}
    file.close();
	return 0;}