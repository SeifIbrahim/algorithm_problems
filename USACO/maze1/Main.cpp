//Wed Nov 25 17:55:50 PST 2015
/*
ID: seifibr1
PROG: maze1
LANG: C++11
*/
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node{
	int i, j, dist;
	Node(int pi = 0, int pj = 0, int pdist = 0):i(pi),j(pj),dist(pdist){}
};

int main() {
	FILE *fin = fopen("maze1.in", "r");
	FILE *fout = fopen("maze1.out", "w");
	int visited[500][500] = {0}, H, W, temp, d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
	char maze[500][500];
	Node n;
	queue<Node> q;
	fscanf(fin, "%d %d\n", &W, &H);
	W = 2 * W + 1, H = 2 * H + 1;
	for (int i = 1; i <= H; i++,fgetc(fin)){
		for(int j = 1; j <= W; j++){
			maze[i][j] = fgetc(fin);
			if(maze[i][j] == ' '){
				int checked = 0;	
				if(i == 1 && ++checked) n = Node(2, j, 1);
				else if (i == H && ++checked) n = Node(H-1, j, 1);
				else if (j == W && ++checked) n = Node(i, W-1, 1); 
				else if (j == 1 && ++checked) n = Node(i, 2, 1);
				if (checked && (maze[i][j] = 'X') && (visited[n.i][n.j] = 1)) 
					q.push(n);
			}
		}
	}
	while(q.size()){
		n = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			Node fence{n.i + d[i][0],n.j + d[i][1],0 };
			Node cell{fence.i+d[i][0], fence.j+ d[i][1], n.dist+1};
			if (maze[fence.i][fence.j] == ' ' && !visited[cell.i][cell.j]) {
				maze[fence.i][fence.j] = 'X', visited[cell.i][cell.j] = 1;
				q.push(cell);
			}
		}
	}
	fprintf(fout, "%d\n", n.dist);
	return 0;
}
