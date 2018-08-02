/*
 ID: seifibr1
 PROG: runround
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

bool isRound(unsigned long i) {
	int array[10] = { 0 };
	int len = log10(i) + 1;
	int x = 0;
	int val = i / (int) (pow(10, len - x - 1)) % 10;
	for (int y = 0; y < len; y++) {
		x = (x + val) % len;
		val = i / (int) (pow(10, len - x - 1)) % 10;
		array[val]++;
		if (val == 0 || array[val] > 1)
			return false;
	}
	return true;
}
int main() {
	ofstream fout("runround.out");
	ifstream fin("runround.in");
	unsigned long num;
	fin >> num;
	while (true) {
		if (isRound(++num)){
			fout << num << endl;
			return 0;
		}
	}
	return 0;
}
