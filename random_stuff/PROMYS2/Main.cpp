
/*
ID: seifibr1
PROG: test
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
	for(int i = 0; i < 100000; i++){
		int x = i*pow(10,ceil(log10(i)))+i;
		double y = sqrt(x);
		if((int)y == y){
			cout << x << endl;
		}	
	}
    return 0;
}
