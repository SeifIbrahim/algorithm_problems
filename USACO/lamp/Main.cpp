//Sun Sep 20 18:41:24 PDT 2015
/*
ID: seifibr1
PROG: lamp
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
vector<int> array(N, 0);

void recurse(int current, vector<int> array){
	if(current <= C){
		for(int i = 1; i <= 4; i++){
			switch(i){
				case 1:
					for(int z = 0; z < N; z++){
						array[z] ^= 1;
					}
					break;
				case 2:
					for(int z = 0; z < N; z+=2){
						array[z] ^= 1;
					}
					break;
				case 3:
					for(int z = 1; z < N; z+=2){
						array[z] ^= 1;
					}
					break;
				case 4:
					for(int z = 0; z < N; z+=4){
						array[z] ^= 1;
					}
					break;

			}
			recurse(++C, array);
		}
	}else{
		for(int x = 0; x < on.size(); x++){
			if(!array[on[x]]){
				return;
			}
		}
		for(int x = 0; x < off.size(); x++){
			if(!array[off[x]]){
				return;
			}
		}
		sol.insert(array);
	}
}

int main() {
	ofstream fout ("lamp.out");
	ifstream fin ("lamp.in");
	fin >> N >> C;
	while(fin >> n && n != -1){
		on.push_back(n);
	}
	while(fin >> n && n != -1){
		off.push_back(n);
	}
	recurse(0, array);
	/*if(sol.size()==0){
		fout << "IMPOSSIBLE" << endl;
	}else{
		for(set<vector<int> >::iterator it = sol.begin(); it != sol.end(); it++){
			for(int i = 0; i < N-1; i++){
				fout << (*it)[i] << " ";
			}
			fout << (*it)[N-1] << endl;
		}
	}*/
	return 0;
}
