//Fri Oct  9 10:15:08 PDT 2015
/*
ID: seifibr1
PROG: ttwo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	int fx, fy, fd = 0, cx, cy, cd = 0, ans = 0;
	char a;
	ofstream fout ("ttwo.out");
	ifstream fin ("ttwo.in");
	int grid[10][10] = {0};
	int d[8] = {0,-1, 1,0, 0,1, -1,0};
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			fin >> a;
			if(a == '*') grid[i][j] = 1;
			if(a == 'F') fx = j, fy = i;
			if(a == 'C') cx = j, cy = i;
		}
	}
	while(!(fx == cx && fy == cy)){
		ans++;
		int tfx = fx + d[fd*2];
		int tfy = fy + d[fd*2 + 1];
		int tcx = cx + d[cd*2];
		int tcy = cy + d[cd*2 + 1];
		if(tfx<0 || tfx>9 || tfy<0 || tfy>9 || grid[tfy][tfx]){
			fd = (fd+1)%4;
		}else{
			fx = tfx, fy = tfy;	
		}
		if(tcx<0 || tcx>9 || tcy<0 || tcy>9 || grid[tcy][tcx]){
			cd = (cd+1)%4;
		}else{
			cx = tcx, cy = tcy;	
		}
		if(ans > 160000){
			ans = 0;
			break;
		}
	}
	fout << ans << endl;
	return 0;
}
