/*
ID: seifibr1
PROG: inflate
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
	int M, N;
	fin >> M >> N;
	int dp[10005] = {0};
	for(int i = 0; i < N; i++){
		int l, p;
		fin >> p >> l;
		for(int j = l; j <= M; j++){
			dp[j] = max(dp[j],dp[j-l]+p);
		}
	}
	fout << dp[M] << endl;
    return 0;
}
