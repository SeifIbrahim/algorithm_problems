//Sat Oct  3 20:40:16 PDT 2015
/*
ID: seifibr1
PROG: concom
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
	int N, s[101][101] = {0}, v[101][101] = {0};
	fin >> N;
	for(int x = 0; x < N; x++){
		int i, j, p;
		fin >> i >> j >> p;
		s[i][j] = p;
	}
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			if(i != j && !v[i][j] && s[i][j] > 50){
				v[i][j] = 1;
				for(int k = 1; k <= 100; k++){
			 		s[i][k] += s[j][k];
					if(v[j][k]) v[i][k] = 1;
				}
				j = 0;
			}
		}
	}
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			if(i != j && v[i][j]) fout << i << " " << j << endl;
		}
	}
    return 0;
}
