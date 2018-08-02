
/*
ID: seifibr1
PROG: cowbasic
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ofstream fout ("cowbasic.out");
ifstream fin ("cowbasic.in");
string retVar;
map<string, int> globalVars;
void eval(string line){
	stringstream s (line);
	string first;
	s >> first;
	if(s.compare("RETURN")==0){
		retVar = first;
		return;
	}else if(isdigit(first[0])){
		getline(fin, line);
		for(int i = 0; i < atoi(first); i++){
			eval(line);
		}
	}else{
		string equal, val;
		s >> equal >> val;
		globalVars.at(atoi(val)); 
	}
}

int main() {
	string line;
	getline(fin, line);
	eval(line);
	cout << globalvars.at(retVar) << endl;
	return 0;
}
