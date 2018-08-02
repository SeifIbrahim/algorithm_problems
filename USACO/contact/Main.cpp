
/*
ID: seifibr1
PROG: contact
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

struct Pattern{
	string str;
	int i;
	Pattern(bitset <13> pstr, int pi){
		int l = 0;
		for(int i = 12; i >= 0; i--){
			if(pstr[i]){
				l = i;
				break;
			}
		}
		str = pstr.to_string().substr(13-l);
		i = pi;
	}
};
bool cmp(Pattern a, Pattern b){
	if(a.i != b.i){
		return a.i > b.i;
	}
	if(a.str.size() != b.str.size()){
		return a.str.size() < b.str.size(); 
	}
	return a.str < b.str;
}
int main() {
	ofstream fout ("contact.out");
	ifstream fin ("contact.in");
	int A, B, N, sequences[8500] = {0};
	string str, temp;
	fin >> A >> B >> N;
	vector <Pattern> v;
	while(getline(fin,temp)){
		str += temp;
	}
	for(int i = 0; i < str.size(); i++){
		for(int j = A; j <= B; j++){
			if(i + j - 1 < str.size()){
				bitset<13> seq(str.substr(i,j));
				seq[j] = 1;
				sequences[seq.to_ulong()]++;
			}
		}
	}
	for(int i = 0; i < 8400; i++){
		if(sequences[i]){
			v.push_back(Pattern(bitset<13>(i),sequences[i]));
		}
	}
	sort(v.begin(),v.end(),cmp);
	int last = -1, counter = 0;
	while(N--){
		if(counter == v.size()) break;
		if(last != v[counter].i){
			fout << v[counter].i << endl << v[counter].str;
			N++;
			last = v[counter].i;
		}else{
			int num = 0;
			while(v[++counter].i == last){
				if((++num)%6 == 0){
					fout << endl; 
				}else{
					fout << " ";
				}
				fout << v[counter].str;
			}
			fout << endl;
		}
	}
	return 0;
}
