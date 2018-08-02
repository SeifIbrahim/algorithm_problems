
/*
ID: seifibr1
PROG: test
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> v(5,0);
	v[0]^=1;
	cout << v[0];
    return 0;
}
