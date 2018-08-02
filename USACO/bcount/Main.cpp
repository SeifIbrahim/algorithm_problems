
/*
ID: seifibr1
PROG: bcount
LANG: C++11
*/
//use segment tree to add and insert in lg(n)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// efficient segTree from http://codeforces.com/blog/entry/18051
struct segTree{
	vector <int> tree;
	int n;
	segTree(int a){
		n = a;
		tree.resize(2*n);
	}
	void set(int i, int value) { 
		for (tree[i += n] = value; i > 1; i >>= 1) tree[i>>1] = tree[i] + tree[i^1];
	}

	int query(int l, int r) { 
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += tree[l++];
			if (r&1) res += tree[--r];
		}
		return res;
	}
};

int main() {
	ofstream fout ("bcount.out");
	ifstream fin ("bcount.in");
	int N, Q;
	fin >> N >> Q;
	segTree s1(N+1), s2(N+1), s3(N+1);
	for(int i = 1; i <= N; i++){
		int b;
		fin >> b;
		switch(b){
			case 1: s1.set(i,1);
					break;
			case 2: s2.set(i,1);
					break;
			case 3: s3.set(i,1);
					break;
		};
	}
	for(int i = 0; i < Q; i++){
		int a, b;
		fin >> a >> b;
		b++;
		fout << s1.query(a,b) << " " << s2.query(a,b) << " " << s3.query(a,b) << endl;
	}
	return 0;
}
