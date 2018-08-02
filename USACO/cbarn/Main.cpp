#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

array<array<array<long long,1001>,1000>,10> cost;

long long n;
long long mod(long long x){
	return x - n*(x>=n);
}

int main(){
	ifstream fin("cbarn2.in");
	ofstream fout("cbarn2.out");
	long long k; fin >> n >> k;
	vector<long long> v(n);
	for(auto &x : v) fin >> x;

	for(long long i = 0; i < n; ++i){
		long long c = 0;
		cost[1][i][0] = 0;
		for(long long l = 1; l <= n; ++l){
			cost[1][i][l] = c += (l-1)*v[mod(i+l-1)];
		}
	}

	for(long long j = 1; j < k;){
		long long j1, j2;
		if(2*j <= k){
			j1 = j2 = j;
		} else{
			j1 = j;
			j2 = 1<<__builtin_ctzll(k-j);
		}
		j = j1+j2;
		for(long long i = 0; i < n; ++i){
			for(long long l = j; l <= n; ++l){
				auto &c = cost[j][i][l] = 1e18;
				long long low = 0, high = l;
				while(low + 6 < high){
					long long m1 = (low+low+high)/3;
					long long m2 = (low+high+high)/3;
					long long v1 = cost[j1][i][m1] + cost[j2][mod(i+m1)][l-m1];
					long long v2 = cost[j1][i][m2] + cost[j2][mod(i+m2)][l-m2];
					if(v1 < v2)
						high = m2;
					else
						low = m1;
				}
				for(long long p = low; p<=high; ++p)
					c = min(c, cost[j1][i][p] + cost[j2][mod(i+p)][l-p]);
			}
		}
	}

	long long ans = 1e18;
	for(long long i = 0; i < n; ++i)
		ans = min(ans, cost[k][i][n]);
	fout << ans << endl;

	return 0;
}
