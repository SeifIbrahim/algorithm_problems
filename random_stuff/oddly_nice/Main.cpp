#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() {
vector<int> dp;
dp.push_back(1);
	for(int i = 2; i <= 1000;i++){
		int numDivisors = 1;
		for(int j = 2; j<=sqrt(i);j++){
			if(i%j==0){
				if(find(dp.begin(), dp.end(), j) != dp.end())numDivisors++;
				if(j!=i/j&&find(dp.begin(), dp.end(), i/j) != dp.end()){
					numDivisors++;
				}
			}
		}
		if(numDivisors%2!=0){
			dp.push_back(i);
		}
		cout << i << " " << numDivisors << " " << ((numDivisors%2!=0) ? "Oddly Nice" : "Oddly Mean")<<endl;
	}
    return 0;
}
