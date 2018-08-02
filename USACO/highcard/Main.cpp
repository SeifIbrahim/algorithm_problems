
/*
ID: seifibr1
PROG: highcard
LANG: C++11
*/
//play the least card that works
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ofstream fout ("highcard.out");
    ifstream fin ("highcard.in");
	int N;
	fin >> N;
	int bessie[50000] = {0};
	int elsie[50000] = {0};
	for(int i = 0; i < N; i++){
		fin >> elsie[i];		
	}
	sort(elsie, elsie + N);
	for(int card = 1, i = 0, j = 0; card<2*N; card++){
		if(i < N && elsie[i] == card){
			i++;
		}else{
			bessie[j] = card;
			j++;
		}
	}
	int ans = 0;
	for(int i = 0, j = 0; i < N && j < N; i++){
		while(j < N && bessie[j] < elsie[i]) j++; //look for the least card that works
		ans++;
		j++;
	}
	fout << ans << endl;
    return 0;
}
