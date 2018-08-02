#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <iterator>
#include <algorithm>

using namespace std;
const int size = 1000;
const int numsize = 5;
int num[] = {4,7,8,15,6};
int cons[size];

void flip(int n){
	for(int i = 0; i < size/n;i++){
		if(i*n+n<size){
			reverse(&cons[i*n],&cons[i*n+n]);
		}
	}
}

int main(){
	reverse(num,num+numsize);
	for(int i =1; i <= size; i++){
		cons[i-1] = i;
	}
	for(int j = 0; j < numsize; j++){
		int x = distance(cons,find(cons,cons+size,num[j]));
		flip(x);
		flip(2*x-1);
		flip(4*x-3);
		flip(3*x-2);
		flip((7*x-3)/2);
		flip((7*x-1)/2);
	}
	for(int i = 0; i < size; i++){
		cout << cons[i] << " ";
	}
	return 0;
}
