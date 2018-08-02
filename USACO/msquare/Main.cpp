
/*
ID: seifibr1
PROG: msquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

string s;

struct State{
	int dist;
	string str;
	string steps;
	State(int _dist, string _str, string _steps){
		dist = _dist;
		str = _str;
		steps = _steps;
	}
};

State BFS(){
	if(s == "12345678") return State(0,"","");
	queue<State> q;
	set<string> visited;
	q.push(State(0,"12345678",""));
	visited.insert("12345678");
	while(!q.empty()){
		State cur = q.front();
		q.pop();
		string str = cur.str;
		string A(str.rbegin(),str.rend());
		if(s == A) return State(cur.dist + 1, A, cur.steps + "A");
		if(!visited.count(A)){
			q.push(State(cur.dist + 1, A, cur.steps + "A"));
			visited.insert(A);
		}
		string B(str[3]+str.substr(0,3)+str.substr(5)+str[4]);
		if(s == B) return State(cur.dist + 1, B, cur.steps + "B");
		if(!visited.count(B)){
			q.push(State(cur.dist + 1, B, cur.steps + "B"));
			visited.insert(B);
		}
		string C(string()+str[0]+str[6]+str[1]+str[3]+str[4]+str[2]+str[5]+str[7]);
		if(s == C) return State(cur.dist + 1, C, cur.steps + "C");
		if(!visited.count(C)){
			q.push(State(cur.dist + 1, C, cur.steps + "C"));
			visited.insert(C);
		}
	}
	return State(0,"","FAIL");
}

int main() {
	ofstream fout ("msquare.out");
	ifstream fin ("msquare.in");
	for(int i = 0; i < 8; i++){
		char c;
		fin >> c;
		s+=c;
	}
	State result = BFS();
	fout << result.dist << endl << result.steps << endl; 
	return 0;
}
