
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


//Optimal with O(N) T.C

#include <bits/stdc++.h> 


int findCelebrity(int n) {
	int top = 0;
	int bottom = n-1;

	while(top<bottom){
		//i can add if both the top and i knows each other and then move the two pointers but this will result in the TLE 
		if(knows(top,bottom)){
			top++;
		}else if(knows(bottom,top)){
			bottom--;
		}
		else{
			top++;
			bottom--;
		}
		
	}

	if(top>bottom) return -1;
	for(int i =0;i<n;i++){
		if(i==top) continue;
		if(!knows(i,top)){
			return -1;
		}
		//you have to check if the celebrity also knows no one as this test case is not checked by the first loop 
		/*
		In the elimination loop, we always compare top vs bottom.

		If top knows bottom, then top is eliminated.

		If bottom knows top, then bottom is eliminated.

		This means:

		The survivor candidate never gets fully checked against all the people on the “earlier side” (the ones that got eliminated).

		So when the loop ends, the survivor might still know some of those earlier eliminated people → especially the previous top.
		 */
		if(knows(top,i)){
			return -1;
		}

	}
	return top;
}