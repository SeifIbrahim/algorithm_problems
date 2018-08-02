
/*
ID: seifibr1
PROG: promote
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct node{
	int prof;
	int id;
	vector<struct node> children;
}nodes[100000];

int dp[100000];

int solve(int i){
	if(dp[i]!=-1)return dp[i];
	int ans = 0;
	for(int j = 0; j < nodes[i].children.size(); j++){
		int child = nodes[i].children.at(j).id;
		if(dp[child] == -1)dp[child] = solve(child);
		if(nodes[child].prof > nodes[i].prof){
			ans += dp[child] + 1;
		}else{
			/*for(int k = 0; k < nodes[child].children.size(); k++){
				int childchild = nodes[child].children.at(k).id;
				ans+=solve(childchild);
			}*/
			ans+=dp[child];
		}
	}
	return ans;
}

int main() {
    ofstream fout ("promote.out");
    ifstream fin ("promote.in");
	int N;
	fin >> N;
	for(int i = 0; i < 100000; i++)dp[i] = -1;
	for(int i = 0; i < N; i++){
		fin >> nodes[i].prof;
		nodes[i].id = i;
	}
	for(int i = 1; i < N; i++){
		int n;
		fin >> n;
		nodes[n-1].children.push_back(nodes[i]);
	}
	for(int i = 0; i < N; i++){
		fout << solve(i) << endl;
	}
    return 0;
}
