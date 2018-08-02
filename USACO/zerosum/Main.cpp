//Thu Oct  1 21:19:11 PDT 2015
/*
ID: seifibr1
PROG: zerosum
LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;
ofstream fout("zerosum.out");

void recurse(int l, int num, int sum, int sign, string str){
	if(N == l){
		if(sum+sign*num==0){
			fout << str << endl;
		}
		return;
	}
	recurse(l+1,10*num + l + 1, sum, sign, str + " " + char(l+1 + '0'));
	recurse(l+1,l+1, sum+sign*num, 1, str + "+" + char(l+1 + '0'));
	recurse(l+1,l+1, sum+sign*num, -1, str + "-" + char(l+1 + '0'));
}

int main() {
	ifstream fin("zerosum.in");
	fin >> N;	
	recurse(1, 1, 0, 1, "1");
	return 0;
}
