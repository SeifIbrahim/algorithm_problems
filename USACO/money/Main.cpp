//Sat Oct  3 13:20:28 PDT 2015
/*
ID: seifibr1
PROG: money
LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("money.out");
	ifstream fin ("money.in");
	long long V, N, coins[25], dp[100001] = {0};
	fin >> V >> N;
	dp[0] = 1;
	for(int i = 0; i < V; i++) fin >> coins[i];
	for(int i = 0; i < V; i++){
		for(int j = coins[i]; j <= N; j++){
			dp[j] += dp[j - coins[i]];
		}
	}
	fout << dp[N] << endl;
	return 0;
}
