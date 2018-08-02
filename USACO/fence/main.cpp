
/*
ID: seifibr1
PROG: fence
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int adj[501][501] = {0};
stack<int> mystack;
void tour(int i){
	for(int j = 1; j < 501; j++){
		if(adj[i][j]){
			adj[i][j] = --adj[j][i];
			tour(j);
		}
	}	
	mystack.push(i);	
}
int main() {
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
	int F, i, j, k;
	bool found = false;
	int count[501] = {0};
	fin >> F;
	for(int x = 0; x < F; x++){
		fin >> i >> j;
		if(x==0)k=i;
		adj[i][j] = ++adj[j][i];
		count[i]++;
		count[j]++;
	}
	for(int i = 1; i < 501; i++){
		if(count[i] % 2 == 1){
			tour(i);
			found = true;
			break;
		}
	}
	if(!found) tour(k);
	while(!mystack.empty()){
		fout << mystack.top() << endl;
		mystack.pop();
	}
    return 0;
}
