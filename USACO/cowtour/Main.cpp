// Thu Nov 26 17:45:52 PST 2015
/*
ID: seifibr1
PROG: cowtour
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int N;
struct Node{
	int x, y;
};
vector <Node> pasture;
double longestt[200];

double distance(int a, int b){
	return sqrt((pasture[b].x - pasture[a].x) * (pasture[b].x - pasture[a].x) + (pasture[b].y - pasture[a].y) * (pasture[b].y - pasture[a].y));
}

double longest(double (&paths)[150]){
	double max = 0;
	for(int i = 0; i < N; i++){
		if(paths[i] != INFINITY && paths[i] > max) max = paths[i];
	}
	return max;
}

void floyd(vector< vector<int> > adj, double (&dist)[150][150]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) dist[i][j] = 0;
			else if(adj[i][j] == 1) dist[i][j] = distance(i,j);
			else dist[i][j] = INFINITY;
		}
	}
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	for(int i = 0; i < N; i++){
		longestt[i] = longest(dist[i]);
	}
}

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	FILE * output = fopen("cowtour.out", "w");
	FILE * input = fopen("cowtour.in", "r");
	size_t len = 0;
	fscanf(input, "%d", &N);
	vector< vector<int> > adj(N, vector<int>(N));
	pasture.resize(N);
	for(int i = 0; i < N; i++) fscanf(input,"%d %d\n",&(pasture[i].x), &(pasture[i].y));
	char * row = NULL;
	for(int i = 0; i < N; i++){
		getline(&row, &len, input);
		for(int j = 0; j < N; j++){
			if(row[j] == '0') adj[i][j] = 0;
			else adj[i][j] = 1;
		}
	}
	double dists[150][150];
	floyd(adj,dists);
	double mini = INFINITY;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j || dists[i][j] != INFINITY) continue;
			double l = longestt[i];
			mini = max(min(mini, l + distance(i, j) + longestt[j]),l);
		}
	}
    fprintf(output, "%.6f\n", mini);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	cout << duration_cast<microseconds>( t2 - t1 ).count() << endl;
	return 0;
}
