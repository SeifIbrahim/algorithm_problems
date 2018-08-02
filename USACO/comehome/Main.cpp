/*
ID: seifibr1
PROG: comehome
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int charToInt(char l)
{
	if (l >= 'a' && l <= 'z') {
		return l - 'a';
	} else {
		return l - 'A' + 26;
	}
}

char intToChar(int i)
{
	if (i <= 25) {
		return char('a' + i);
	} else {
		return char('A' + (i - 26));
	}
}
int main() {
	ofstream fout ("comehome.out");
	ifstream fin ("comehome.in");
	int N, min, min_ans = 0xFFFFFF;
	fin >> N;
	int dists[52][52] = {0};
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			dists[i][j] = 0xFFFFFF;
		}
	}
	for(int i = 0; i < N; i++){
		char a, b;
		int dist = 0;
		fin >> a >> b >> dist; 
		int c = charToInt(a);
		int d = charToInt(b);
		if(dist < dists[c][d]){
			dists[c][d] = dists[d][c] = dist;
		}
	}
	for(int i = 0; i < 52; i++){
		dists[i][i] = 0;
	}
	for(int k = 0; k < 52; k++){
		for(int i = 0; i < 52; i++){
			for(int j = 0; j < 52; j++){
				if(dists[i][k] + dists[k][j] < dists[i][j]){
					dists[i][j] = dists[i][k] + dists[k][j]; 
				}
			}
		}
	}
	for (int i = 26; i < 51; i++) {
		if (dists[i][51] < min_ans) {
			min_ans = dists[i][51];
			min = i;
		}
	}
	fout << intToChar(min) << " " << min_ans << endl;
	return 0;
}
