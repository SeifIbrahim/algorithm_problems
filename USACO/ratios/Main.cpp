
/*
ID: seifibr1
PROG: ratios
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int target[3];
int feed[3][3];
int possible[3];

int check(){
	int total[3] = {0};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			total[j] += possible[i] * feed[i][j];
		}
	}	
	for(int i = 0; i < 3; i++){
		if(target[i]!=0){
			if(total[i]%target[i]!=0){
				return 0;
			}else{
				int rate = total[i]/target[i];
				if((rate*target[0]==total[0])&&(rate*target[1]==total[1])&&(rate*target[2]==total[2])){
					return rate;
				}
			}
		}
	}
	return 0;
}

int main() {
	ofstream fout ("ratios.out");
	ifstream fin ("ratios.in");
	for(int i = 0; i < 3; i++){
		fin >> target[i];
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			fin >> feed[i][j];
		}
	}
	for(possible[0] = 0; possible[0] < 100; possible[0]++ ){
		for(possible[1] = 0; possible[1] < 100; possible[1]++ ){
			for(possible[2] = 0; possible[2] < 100; possible[2]++ ){
				int result = check();
				if(result){
					fout << possible[0] << " " << possible[1] << " " << possible[2] << " " << result << endl;
					return 0;
				}
			}
		}
	}
	fout << "NONE" << endl; return 0;
}
