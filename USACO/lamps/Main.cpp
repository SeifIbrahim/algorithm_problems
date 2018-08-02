//Sun Sep 20 18:41:24 PDT 2015
/*
ID: seifibr1
PROG: lamps
LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> on;
vector<int> off;
set<vector<int> > sol;
int N, C, n;

void recurse(int current, vector<int> larray){
	if(current <= 2 && current <= C){
		for(int i = 1; i <= 5; i++){
			vector <int> temp = larray;
			switch(i){
				case 1:
					for(int z = 0; z < N; z++){
						temp[z] ^= 1;
					}
					break;
				case 2:
					for(int z = 0; z < N; z+=2){
						temp[z] ^= 1;
					}
					break;
				case 3:
					for(int z = 1; z < N; z+=2){
						temp[z] ^= 1;
					}
					break;
				case 4:
					for(int z = 0; z < N; z+=3){
						temp[z] ^= 1;
					}
					break;
				case 5:
					break;

			}
			recurse(current+1, temp); 
		}
	}else{
		for(int x = 0; x < on.size(); x++){
			if(!larray[on[x]-1]){
				return;
			}
		}
		for(int x = 0; x < off.size(); x++){
			if(larray[off[x]-1]){
				return;
			}
		}
		sol.insert(larray);
	}
}

int main() {
	ofstream fout ("lamps.out");
	ifstream fin ("lamps.in");
	fin >> N >> C;
	vector<int> aarray(N, 1);
	while(fin >> n && n != -1){
		on.push_back(n);
	}
	while(fin >> n && n != -1){
		off.push_back(n);
	}
	recurse(1,aarray);
	if(sol.size()==0){
		fout << "IMPOSSIBLE" << endl;
	}else{
		for(set<vector<int> >::iterator it = sol.begin(); it != sol.end(); it++){
			for(int i = 0; i < N-1; i++){	
				fout << (*it)[i];
			}
			fout << (*it)[N-1] << endl;
		}
	}
	return 0;
}
