/*
ID: seifibr1
PROG: camelot
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Piece{
	int r, c;
	Piece(){};
	Piece(int i, int j): c(i), r(j) {};
}knights[30*26];

int main() {
	ofstream fout ("camelot.out");
	ifstream fin ("camelot.in");
	char c;
	int r, R, C, K=0;
	int adj[30][30][30][30];
	memset(adj, 1, sizeof(adj));
	int deltac[] = {-2,-2,-1,-1,1,1,2,2};
	int deltar[] = {-1,1,-2,2,-2,2,-1,1};

	fin >> R >> C;

	fin >> c >> r; 
	struct Piece king(c-'A', r-1);

	while(fin >> c >> r){
		knights[K].c = c-'A';
		knights[K++].r = r-1;
	}

	queue<struct Piece> q;
	for(int i = 0; i < C; i++){
		for(int j = 0; j < R; j++){
			adj[i][j][i][j] = 0;
			q.push(Piece(i,j));
			while(!q.empty()){
				struct Piece p = q.front(); q.pop();
				for(int k = 0; k < 8; k++){
					int newR = p.r+deltar[k];
					int newC = p.c+deltac[k];
					if(newR >= 0 && newR < R && newC >= 0 && newC < C && adj[i][j][newC][newR] == 0x01010101){
						adj[i][j][newC][newR] = adj[i][j][p.c][p.r] + 1;
						q.push(Piece(newC, newR));
					}
				}
			}
		}
	}
	int ans = 0x7fffffff;
	for(int i = 0; i < C; i++){
		for(int j = 0; j < R; j++){
			int allGo = 0;
			for(int k = 0; k < K; k++){
				allGo += adj[i][j][knights[k].c][knights[k].r];
			}
			int extra = max(abs(i-king.c), abs(j-king.r));
			int s = 2;
			for(int kingC = ((king.c - s < 0) ? 0 : king.c - s); kingC <= ((king.c+s > C-1)? C-1: king.c + s); kingC++){
				for(int kingR = ((king.r - s < 0) ? 0:king.r - s); kingR <= ((king.r + s > R - 1)? R - 1: king.r + s); kingR++){
					for(int k = 0; k < K; k++){
						extra = min(extra, adj[knights[k].c][knights[k].r][kingC][kingR] + adj[kingC][kingR][i][j] - adj[knights[k].c][knights[k].r][i][j] + max(abs(kingC-king.c), abs(kingR-king.r)));
					}
				}
			}
			ans = min(ans, allGo+extra);
		}
	}
	fout << ans << endl;
	return 0;
}
