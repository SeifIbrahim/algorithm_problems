#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1010
#define MAXK 10
#define INF 0x3FFFFFFFFFFFFFFFLL

int N, K;
long long A[MAXN];
long long DP[MAXK][MAXN];

int main() {
	ifstream fin("cbarn2.in");
	ofstream fout("cbarn2.out");
	fin >> N >> K;
	for (int i = 0; i < N; i++) {
		fin >> A[i];
	}

	long long result = INF;
	for (int i = 0; i < N; i++) {
		memset(DP, 0x3F, sizeof(DP));
		DP[0][N] = 0;

		for (int k = 1; k <= K; k++) {
			for (int j = 0; j < N; j++) {
				long long val = 0;
				for (int a = j + 1; a <= N; a++) {
					val += A[a - 1] * (a - j - 1);
					DP[k][j] = min(DP[k][j], val + DP[k - 1][a]);
				}
			}
		}
		result = min(result, DP[K][0]);
		rotate(A, A + 1, A + N);
	}
	fout << result << endl;
}
