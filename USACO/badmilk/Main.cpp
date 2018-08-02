
/*
ID: seifibr1
PROG: badmilk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct person{
	vector <vector<int> > drank;
};
int main() {
	FILE *fout = fopen ("badmilk.out", "w");
	ifstream fin ("badmilk.in");
	int N, M, D, S;
	int ans = 0;
	fin >> N >> M >> D >> S;
	int bad[51];
	int same[51]={0};
	fill_n(bad, 51, 2);
	person people[51];	
	for(int i = 0; i < D; i++){
		int person, milk, time;
		fin >> person >> milk >> time;
		people[person].drank.push_back({milk, time});
	}
	for(int i = 0; i < S; i++){
		int person, time;	
		fin >> person >> time;
		for(int j = 0; j < people[person].drank.size(); j++){
			if(people[person].drank[j][1] < time && bad[people[person].drank[j][0]]!=0){
				bad[people[person].drank[j][0]] = 1;
				same[j] = person;
			}else if(people[person].drank[j][1] >= time && same[j]!=person){
				bad[people[person].drank[j][0]] = 0;
			}
		}
		for(int x = 1; x <=50;x++){
			bool drank = false;
			for(int y = 0; y < people[person].drank.size(); y++){
				if(x==people[person].drank[y][0]){
					drank = true;
				}
			}
			if(drank==false){
				bad[x] = 0;
			}
		}
	}
	for(int i = 1; i <= M; i++){
		if(bad[i]==1){
			int temp = 0;
			for(int j = 1; j <= N; j++){
				for(int k = 0; k < people[j].drank.size(); k++){
					if(people[j].drank[k][0] == i){
						temp++;
						break;
					}
				}
			}
			ans = max(ans, temp);
		}
	}
	fprintf (fout, "%d\n", ans);
	return 0;
}
