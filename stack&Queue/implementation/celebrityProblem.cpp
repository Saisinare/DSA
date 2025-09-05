
#include <bits/stdc++.h> 
using namespace std;

//dummy helper function as this is already provided by the coding ninjas 
bool knows(int i ,int j){
    return true;
}

int findCelebrity(int n) {
	vector<int> knowsMe(n,0);
	vector<int> known(n,0);



 	for(int i =0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(j==i) continue;
			if(knows(i,j)){
				knowsMe[j]++;
				known[i]++;
			}
		}
	}

	for(int i =0;i<n;i++){
		if(known[i]==0 && knowsMe[i]==n-1){
			return i;
		}
	}

	return -1;
}