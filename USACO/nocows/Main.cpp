
//Wed Sep 30 10:12:38 PDT 2015
/*
ID: seifibr1
PROG: nocows
LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("nocows.out");
	ifstream fin ("nocows.in");
	int N, K;
	fin >> N >> K;
	if(N%2==0){
		fout << 0 << endl;
		return 0;
	}
	K--;
	N/=2;
	int	dp[102][202] = {0};
	for(int i = 0; i <= K; i++){
		dp[i][0] = 1;
	}
	for(int i = 1; i <= K; i++){
		for(int j = 1; j <= N; j++){
			for(int m = 0; m < j; m++){
			dp[i][j] += (dp[i-1][m] * dp[i-1][j-m-1]);
			dp[i][j] %= 9901;
			}
		}
	}
	fout << (dp[K][N] - dp[K-1][N] + 9901)%9901 << endl;
	return 0;
}
