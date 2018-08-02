/*
ID: seifibr1
PROG: prefix
LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	ofstream fout ("prefix.out");
	ifstream fin ("prefix.in");
	bool can_add[200001] = {0};
	int plength[201];
	string target, prefix[201];
	char str[78];
	int len, ans, i = 0;
	while(fin >> str && strcmp(str, ".")){
		plength[i] = strlen(str);
		prefix[i++] = str;
	}
	while(fin >> str){
		target += str;
	}
	len = target.length();
	can_add[0] = true;
	for(int j = 0; j <= len; j++){
		if(can_add[j]){
			ans = j;
			for(int k = 0; k < i; k++){
				if(plength[k] + j <= len){
					for(int l = 0; l < plength[k]; l++){
						if(target[j+l] != prefix[k][l]){
							goto A;
						}
					}
					can_add[j+plength[k]]=true;
					A:;
				}
			}
		}
	}
	fout << ans << endl;
	return 0;
}
