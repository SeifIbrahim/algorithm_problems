
#include <vector>
#include <string>
#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
struct S{
	long long x;
	bool horz;
};
bool operator<(S l, S r){
	return l.x < r.x;
}
string filename = "fencedin";
int main(){
	ifstream fin(filename+".in");
	ofstream fout(filename+".out");

	long long A, B, n, m; fin >> A >> B >> n >> m;
	vector<long long> av(n), bv(m);
	for(auto &x : av) fin >> x;
	for(auto &x : bv) fin >> x;
	av.push_back(0);
	bv.push_back(0);
	av.push_back(A);
	bv.push_back(B);
	sort(av.begin(),av.end()); sort(bv.begin(),bv.end());

	vector<S> v;
	for(int i=0;i<n+1;i++) v.push_back({av[i+1]-av[i], true});
	for(int i=0;i<m+1;i++) v.push_back({bv[i+1]-bv[i], false});

	sort(v.begin(),v.end());

	long long hdone=0, vdone=0;

	long long ans = 0;
	long long bars = 0;
	for(auto s : v){
		bool h = s.horz;
		long long width = s.x;
		long long inc = 0;
		long long count = 0;
		if(h){
			if(hdone == 0 || vdone==0)
				count = m;
			else
				count = m-vdone+1;
			inc = count * width;
			++hdone;
		} else {
			if(hdone == 0 || vdone==0)
				count = n;
			else
				count = n-hdone+1;
			inc = count * width;
			++vdone;
		}
		bars += count;
		ans += inc;
	}
	cout << bars << endl;
	fout << ans << endl;


	return 0;
}
