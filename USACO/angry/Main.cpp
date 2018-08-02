
/*
ID: seifibr1
PROG: angry
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct haybale{
	double l,r;
	double radius = 0;
	haybale(double _l,double _r, double _radius){
		l = _l;
		r = _r;
		radius = _radius;
	}
};

bool check(double loc, double rad){
	queue<int> q;
	int[1000000001] visited = {0};
	if(rad+loc != (int)(rad+loc)rad+=.5
	for(double i=0; i <= rad; i++){
		if(find(unsorted.begin(),unsorted.end(),loc+i)!=0&&!visited[i]) q.push(i);
		if(find(unsorted.begin(),unsorted.end(),loc-i)!=0&&!visited[i]) q.push(i);
	}
	while()
}
int main() {
	ofstream fout ("angry.out");
	ifstream fin ("angry.in");
	int N,i;
	double res = 1000000001;
	fin >> N;
	vector<haybale> points;	
	vector<double> unsorted;
	for(int i = 0; i < N; i++){
		int a;
		fin >> a;
		unsorted.push_back(a);
	}
	sort(unsorted.begin(), unsorted.end());
	points.push_back(haybale(0, unsorted[1]-unsorted[0]));
	for(i = 1; i < unsorted.size()-1; i++){
		points.push_back(haybale(unsorted[i]-unsorted[i-1]+1,unsorted[i+1]-unsorted[i]));
	}
	points.push_back(haybale(unsorted[i]-unsorted[i-1],0));
	for(int i = 0; i < points.size(); i++){
		double rad = 0;
		while(!check((unsorted[i+1]-unsorted[i])/2,rad))rad+=.5;
		//res = min(res,max(max(points[i].l,points[i+1].r),(unsorted[i+1]-unsorted[i])/2));
		res = min (res, rad);
	}
	fout << res << endl;
	return 0;
}
