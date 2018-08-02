/*
ID: seifibr1
PROG: fact4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("fact4.out");
	ifstream fin ("fact4.in");
	int N, last;
	fin >> N;
	last = N;
	for(int i = N - 1; i >= 1; i--){
		last = last*i%100000;
		while(last%10==0) last /= 10;
	}
	fout << last % 10 << endl;
	return 0;
}
