
/*
ID: seifibr1
PROG: butter
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#define INF 10000000

using namespace std;

struct comp{
	bool operator() (const pair <int,int> &lhs, const pair<int,int> &rhs) const {
		if(lhs.second == rhs.second) return lhs.first < rhs.first;
		return lhs.second < rhs.second;
	}
};

int cows[501];
int adj[801][801];
int total[801];
int N, P, C;
int dist[801];
bool visited[801];

void dijkstra(int i){
	set <pair<int,int>, comp> queue;
	for(int j = 0; j < P; j++){
		dist[j] = adj[i][j];
		visited[j] = false; 
	}
	queue.insert(pair<int,int>(i,0));
	int c = 0;
	while(!queue.empty()){
		pair <int,int> node = *queue.begin();
		queue.erase(queue.begin());
		if(visited[node.first]) continue;
		visited[node.first] = true;
		c++;
		if(c == P) break;
		for(int j = 0; j < P; j++){
			if(adj[node.first][j] + node.second <= dist[j] && adj[node.first][j] < INF && !visited[j]){
				dist[j] = adj[node.first][j] + node.second;
				queue.insert(pair<int,int>(j, dist[j]));
			}
		}
	}

	for(int j = 0; j < P; j++){
		total[j] += dist[j];
	}
}

int main() {
	ofstream fout ("butter.out");
	ifstream fin ("butter.in");
	int ans = INF;
	fin >> N >> P >> C;
	for (int i = 0; i < N; i++){
		int j; fin >> j; j--;
		cows[i] = j;
	}
	for(int i = 0; i < P; i++){
		for(int j = 0; j < P; j++){
			adj[i][j] = adj[j][i] = INF;
		}
	}
	for(int i = 0; i < C; i++){
		int x, y, z;
		fin >> x >> y >> z;
		x--; y--;
		adj[x][y] = adj[y][x] = min (adj[x][y], z);
	}
	for(int i = 0; i < P; i++) adj[i][i] = 0;
	for(int i = 0; i < N; i++){
		dijkstra(cows[i]);	
	}	
	for(int i = 0; i < P; i++){
		ans = min(ans, total[i]);
	}
	fout << ans << endl;
	return 0;
}
