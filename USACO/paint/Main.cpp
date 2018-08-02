
/*
ID: seifibr1
PROG: paint
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");
	int ans = 0;
	int array[101] = {0};
	for(int a,b; fin >> a >> b;){
		for(int i = a; i<b; i++){
			array[i] = 1;
		}
	}
	for(int i = 0; i < 101; i++){
		if(array[i] == 1){
			ans++;
		}
	}
	fout << ans << endl;
    return 0;
}
