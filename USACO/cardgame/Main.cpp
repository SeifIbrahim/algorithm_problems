
/*
ID: seifibr1
PROG: cardgame
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout ("cardgame.out");
	ifstream fin ("cardgame.in");
	int N;
	fin >> N;
	int bessie[50000] = {0};
	int elsie[50000] = {0};
	int elsie2[50000] = {0};//used only to find bessie's cards
	int bigger[50000] = {0};//how many bigger cards we have for each of elsie's cards
	int smaller[50000] = {0};//same as bigger but for second stage
	for(int i = 0; i < N; i++){
		fin >> elsie[i];		
		elsie2[i]=elsie[i];
	}
	sort(elsie2, elsie2 + N);
	for(int card = 1, i = 0, j = 0; card<2*N; card++){
		if(i < N && elsie2[i] == card){
			i++;
		}else{
			bessie[j] = card;
			j++;
		}
	}
	int middle = N/2;
	//sort the indivitual halves of the game
	sort(elsie, elsie+middle);
	sort(elsie + middle, elsie + N);

	for(int i = middle-1, j = N-1; i >= 0; i--){
		while(bessie[j] > elsie[i] && j >= 0){
			bigger[i]++;
			j--;
		}
		if(i>0){//we have bigger cards than all the cards smaller than this one
			bigger[i-1] = bigger[i];	
		}
	}
	for(int i = middle, j = 0; i < N; i++){
		while(bessie[j] < elsie[i] && i < N){
			smaller[i]++;
			j++;
		}
		if(i<N){
			smaller[i+1] = smaller[i];	
		}
	}
	//use the largest cards on part one and use the rest on part 2
	int big = 0, small = 0;
	for(int i = middle-1; i>=0; i--){
		if(bigger[i]>big){
			big++;
		}
	}
	for(int i = middle; i<N; i++){
		if(smaller[i]>small){
			small++;
		}
	}
	fout << big+small << endl;
	return 0;
}
