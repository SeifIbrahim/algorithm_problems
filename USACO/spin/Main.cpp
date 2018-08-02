
/*
ID: seifibr1
PROG: spin
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Wheel{
	int velocity, nWedges, wedges[5][2];
};

int main() {
	Wheel w[5];
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
	for(int i = 0; i < 5; i++){
		fin >> w[i].velocity >> w[i].nWedges;
		for(int j = 0; j < w[i].nWedges; j++){
			fin >> w[i].wedges[j][0] >> w[i].wedges[j][1];
		}
	}
	for(int time = 0; time <= 360; time++){
		int l[360] = {0};
		for(int i = 0; i < 5; i++){
			int start = time*w[i].velocity;
			for(int j = 0; j < w[i].nWedges; j++){
				for(int k = w[i].wedges[j][0] + start; k <= w[i].wedges[j][0] + w[i].wedges[j][1]+ start; k++){
					l[k%360]++;
					if(l[k%360] == 5){
						fout << time << endl;
						return 0;
					}
				}
			}
		}
	}	
	fout << "none" << endl;
    return 0;
}
