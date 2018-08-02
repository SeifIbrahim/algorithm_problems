#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
	int a = rand()%32;
	int i = a;
	int j = a;
	int b = 2*(rand()%16);
	do{
		i++;
		i%=32;
		a+=b;
		a%=32;
		cout << (a^i) << endl;
	}while(i!=j);
    return 0;
}
