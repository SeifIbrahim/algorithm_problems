/*
ID: seifibr1
PROG: lightson
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Switch{
	int a, b;
	Switch(int c, int d): a(c), b(d){}
};

int main() {
	ofstream fout ("lightson.out");
	ifstream fin ("lightson.in");
	int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
	bool visited[101][101] = {0};
	bool lit[101][101] = {0};
	visited[1][1] = true;
	lit[1][1] = true;
	queue <Switch> canVisit;
	canVisit.push(Switch(1,1));
	int N, M;
	fin >> N >> M;
	vector<vector<vector<Switch> > > farm;
	farm.resize(101);
	for(int i = 0; i < 101; i++){
		farm[i].resize(101);
	}
	for(int i = 0; i <= M; i++){
		int x, y, a, b;
		fin >> x >> y >> a >> b;
		farm[x][y].push_back(Switch(a,b));
	}
	while(!canVisit.empty()){
		Switch t = canVisit.front();
		canVisit.pop();
		for(const Switch& s : farm[t.a][t.b]){
			lit[s.a][s.b] = true;
			if(!visited[s.a][s.b]){
				for(int i = 0; i < 4; i++){
					int a = s.a + dir[i][0], b = s.b + dir[i][1];
					if (a >= 1 && a <= N && b >= 1 && b <= N && visited[a][b]) {
						canVisit.push(s);
						visited[s.a][s.b] = true;
					}
				}
			}
		}
		for(int i = 0; i < 4; i++){
			int a = t.a + dir[i][0], b = t.b + dir[i][1];
			if(lit[a][b] && !visited[a][b] && a >= 1 && a <= N && b >= 1 && b <= N){
				canVisit.push(Switch(a, b));
				visited[a][b] = true;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <=N; j++){
			if(lit[i][j]){
				ans++;
			}
		}
	}
	fout << ans << endl;
	return 0;
}
