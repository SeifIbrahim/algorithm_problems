
/*
ID: seifibr1
PROG: humble
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout ("humble.out");
	ifstream fin ("humble.in");
	int K, N;
	fin >> K >> N;
	int primes[100];
	int next[100000] = {0};
	unsigned int humble[100001];
	for(int i = 0; i < K; i++){
		fin >> primes[i];
	}
	humble[0] = 1;
	for(int i = 1; i<=N; i++){
		humble[i] = 2147483647;
		for(int j = 0; j<K; j++){
			humble[i]=min(humble[i],primes[j]*humble[next[j]]);
		}	
		for(int j = 0; j<K; j++){
			if(humble[i]>=primes[j]*humble[next[j]]) next[j]++;
		}	
	}	
	fout << humble[N] << endl;
	return 0;
}
