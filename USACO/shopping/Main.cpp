
/*
ID: seifibr1
PROG: shopping
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct offer{
	int items[6];
	int price;
}offers[105];

int idx = 0;
int codes[1000] = {0};
int translate(int c){
	if(codes[c] == 0) codes[c] = ++idx;
	return codes[c];
}

int main() {
	ofstream fout ("shopping.out");
	ifstream fin ("shopping.in");
	int S,N;
	int needed[6] = {0};
	int dp[6][6][6][6][6];

	fin >> S;
	for(int i = 0; i < S; i++){
		fin >> N;
		for(int j = 0; j < N; j++){
			int c, k;
			fin >> c >> k;
			offers[i].items[translate(c)] = k;
		}	
		fin >> offers[i].price;
	}
	fin >> N;
	for (int i = 0; i < N; i++){
		int c, k, p;
		fin >> c >> k >> p;
		offers[S+i].items[translate(c)] = 1;
		offers[S+i].price = p;
		needed[translate(c)] = k;
	}

	memset(dp,127,sizeof(dp));
	dp[0][0][0][0][0] = 0;
	for(int a = 0 ; a < S+N; a++){
		int i = offers[a].items[1];
		int j = offers[a].items[2];
		int k = offers[a].items[3];
		int l = offers[a].items[4];
		int m = offers[a].items[5];
		for(int b = 0; b + i <= needed[1]; b++){
			for(int c = 0; c + j <= needed[2]; c++){
				for(int d = 0; d + k <= needed[3]; d++){
					for(int e = 0; e + l <= needed[4]; e++){
						for(int f = 0; f + m <= needed[5]; f++){
							dp[i+b][j+c][k+d][l+e][m+f] = min(dp[i+b][j+c][k+d][l+e][m+f], dp[b][c][d][e][f] + offers[a].price);
						}
					}
				}
			}
		}
	}

	fout << dp[needed[1]][needed[2]][needed[3]][needed[4]][needed[5]] << endl;

	return 0;
}
