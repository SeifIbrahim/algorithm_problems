
/*
ID: seifibr1
PROG: speeding
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	FILE *fout = fopen ("speeding.out", "w");
    ifstream fin ("speeding.in");
	int N = 0, M = 0, start = 1, ans = 0;
	int array[101][2];
	fin >> N >> M;
	for(int i = 0; i < N; i++){
		int dist, speed;
		fin >> dist >> speed;
		for(int j = start; j < start+dist; j++){
			array[j][0] = speed;
		}
		start+=dist;
	}
	start = 1;
	for(int i = 0; i < M; i++){
		int dist, speed;
		fin >> dist >> speed;
		for(int j = start; j < start+dist; j++){
			array[j][1] = speed;
		}
		start+=dist;
	}
	for(int i = 1; i < 101; i++){
		if(array[i][1] - array[i][0] > ans){
			ans = array[i][1] - array[i][0];
		}
	}
	fprintf (fout, "%d\n", ans);
    return 0;
}
