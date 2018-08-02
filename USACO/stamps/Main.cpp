
/*
ID: seifibr1
PROG: stamps
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("stamps.out");
	ifstream fin ("stamps.in");
	int N, K, i;
	fin >> K >> N;
	int dp[2000000], coins[200];
	for(int i = 0; i < N; i++){
		fin >> coins[i];
	}
	dp[0] = 0;
	for(i = 1; i < K * 100000; i++){
		dp[i] = K * 100000;
		for(int j = 0; j < N; j++){
			if(coins[j] <= i){
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		if(dp[i] > K) break;
	}
	fout << i - 1 << endl; 
	return 0;
}
