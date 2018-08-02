package maxflow;

import java.io.*;
import java.util.*;

public class maxflow {
	static int[] p;
	static int[] depth;
	static int[][] anc;
	static int[] amt;
	static LinkedList<Integer>[] edges;
	static LinkedList<Integer> revOrder;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(
				new FileReader("/Users/home/Documents/workspace/maxflow/src/maxflow/maxflow.in"));
		PrintWriter pw = new PrintWriter(
				new BufferedWriter(new FileWriter("/Users/home/Documents/workspace/maxflow/src/maxflow/maxflow.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		p = new int[n + 1];
		amt = new int[n + 1];
		depth = new int[n + 1];
		Arrays.fill(p, -1);
		p[0] = p[1] = 0;
		anc = new int[n + 1][17];
		edges = new LinkedList[n + 1];
		revOrder = new LinkedList<Integer>();
		for (int i = 0; i < edges.length; i++) {
			edges[i] = new LinkedList<Integer>();
		}
		for (int a = 1; a < n; a++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			edges[x].add(y);
			edges[y].add(x);
		}
		bfs();
		genLCA();
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int lca = lca(x, y);
			amt[x]++;
			amt[y]++;
			amt[lca]--;
			amt[p[lca]]--;
		}
		compute();
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			ret = Math.max(ret, amt[i]);
		}
		pw.println(ret);
		pw.close();
	}

	public static void compute() {
		while (!revOrder.isEmpty()) {
			int curr = revOrder.removeFirst();
			amt[p[curr]] += amt[curr];
		}
	}

	public static int lca(int a, int b) {
		if (depth[a] > depth[b]) {
			return lca(b, a);
		}
		if (depth[a] < depth[b]) {
			b = getP(b, depth[a]);
		}
		for (int k = 16; k > 0; k--) {
			while (anc[a][k] != anc[b][k]) {
				a = anc[a][k];
				b = anc[b][k];
			}
		}
		while (a != b) {
			a = p[a];
			b = p[b];
		}
		return a;
	}

	public static int getP(int curr, int wantedD) {
		for (int k = 16; depth[curr] != wantedD; k--) {
			while (depth[curr] - (1 << k) >= wantedD) {
				curr = anc[curr][k];
			}
		}
		return curr;
	}

	public static void genLCA() {
		for (int i = 1; i < p.length; i++) {
			anc[i][0] = p[i];
		}
		for (int j = 1; j < anc[0].length; j++) {
			for (int i = 1; i < p.length; i++) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
		}
	}

	public static void bfs() {
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(1);
		while (!q.isEmpty()) {
			int curr = q.removeFirst();
			revOrder.addFirst(curr);
			for (int child : edges[curr]) {
				if (p[child] == -1) {
					p[child] = curr;
					depth[child] = 1 + depth[curr];
					q.add(child);
				}
			}
		}
	}
}