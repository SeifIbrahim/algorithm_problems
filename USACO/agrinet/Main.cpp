
/*
ID: seifibr1
PROG: agrinet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct comparator {

	bool operator()(int i, int j) {
		return i > j;
	}
};

int main() {
	ofstream fout ("agrinet.out");
	ifstream fin ("agrinet.in");
	int N;
	fin >> N;
	int dist[101];
	bool intree[101] = {0};
	int matrix[101][101];
	intree[0] = true;
	int treecost = 0;
	int treesize = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			fin >> matrix[i][j];
		}
	}
	for(int i = 0; i<N; i++){
		dist[i] = matrix[0][i];
	}
	while(treesize<N){
		int minval = 100001;
		int minindex;
		for(int i = 1; i < N; i++){
			if(!intree[i] && dist[i]<minval){
				minval = dist[i];
				minindex = i;
			}
		}
		intree[minindex] = true;
		treesize++;
		treecost+=minval;
		for(int i = 0; i<N; i++){
			if(dist[i]>matrix[minindex][i]){
				dist[i] = matrix[minindex][i];
			}
		}
	}
	fout << treecost << endl;
	return 0;
}
