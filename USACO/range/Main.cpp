
/*
ID: seifibr1
PROG: range
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	ofstream fout ("range.out");
	ifstream fin ("range.in");
	int N;
	int field[250][250];
	int dp[250][250];
	int patches[250];
	char c[250];
	memset(field, 0, sizeof(int)*250*250);
	memset(dp, 0, sizeof(int)*250*250);
	memset(patches, 0, sizeof(int)*250);
	fin >> N;
	for(int i = 0; i < N; i++){
		fin >> c;
		for(int j = 0; j < N; j++){
			field[i][j] = c[j] - '0';
		}	
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == 0 || j == 0){
				dp[i][j] = field[i][j];
			}else if(field[i][j] == 1){
				dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < dp[i][j]; k++){
				patches[k]++;
			}
		}
	}
	for(int i = 1; i < N; i++){
		if(patches[i] > 0){
			fout << i+1 << " " << patches[i] << endl;
		}
	}
	return 0;
}
