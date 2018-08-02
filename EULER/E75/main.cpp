
/*
ID: seifibr1
PROG: euclidtotherescue
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int gcd(int a, int b) { //euclid algorithm gcd (copy/paste)
	int t;
	while(b != 0){
		t = a;
		a = b;
		b = t%b;
	}
	return a;
}

int main() {
	const int lim = 1500000;
	int mem[lim+1] = {0};
	int ans = 0;
	for(long i = 2; i < sqrt(lim); i++){ //longest side is 2*lim^2 (can be further optimized)
		for(long j = 1; j < i; j++){
			if((i+j)%2==1&&gcd(i,j)==1){ //apparently this is how you ensure they're unique (wikipedia)
				long a = i*i + j*j;
				long b = i*i - j*j;
				long c = 2*i*j;
				for(int k = a+b+c; k<=lim; k+=a+b+c){ //iterate through similar triangles
					mem[k]++; 
				}
			}
		}
	}
	for(int i = 0; i < lim+1; i++){
		if(mem[i] == 1){
			 ans++;
			 cout << i << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
