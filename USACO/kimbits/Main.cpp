
/*
ID: seifibr1
PROG: kimbits
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
	long long N, L, I; 
	long long dp[32][32];
	fin >> N >> L >> I;
	for(int i = 0; i <= N; i++){
		dp[i][0] = dp[0][i] = 1;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	for(int i = N-1; i >= 0; i--){
		if(dp[i][L]<I){
			fout << 1;
			I -= dp[i][L--];
		}else{
			fout << 0;
		}
	}
	fout << endl;
    return 0;
}
