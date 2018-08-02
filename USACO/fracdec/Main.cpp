// Thu Dec  3 17:18:25 PST 2015
/*
ID: seifibr1
PROG: fracdec
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");

void out(string ans){
    if(ans.length() <= 76) fout << ans << endl;
    else{
        for(int i = 0; i < ans.length(); i += 76){
            fout << ans.substr(i, 76) << endl;
        }
    }
}
int main() {
	int N, D;
	fin >> N >> D;
	int R[D];
	int r = N % D;
	string fraction = "";
	memset(R, -1, sizeof(R));
	bool repeating = true;
	R[r] = 0;
	while(repeating){
		fraction += to_string(10 * r / D);
		r = 10 * r % D;
		if(r == 0){
			out(to_string(N/D) + "." + fraction);
			return 0;
		}
		if(R[r] != -1) repeating = false;
		else R[r] = fraction.length(); 
	}
	fraction = fraction.substr(0, R[r]) + "(" + fraction.substr(R[r], fraction.length()) + ")";
	out(to_string(N/D) + "." + fraction);
    return 0;
}
