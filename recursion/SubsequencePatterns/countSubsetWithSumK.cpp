#include<bits/stdc++.h>
using namespace std;

int backtrack(vector<int>& arr, int target, int sum, int index) {
	if(sum>target){
		return 0;
	}
	if(index>=arr.size()){
	    	if(sum==target){
		        return 1;
	        }else return 0;
	}

	int ans1 = backtrack(arr,target,sum+arr[index],index+1);
	int ans2 = backtrack(arr,target,sum,index+1);
	return ans1+ans2;
}

int findWays(vector<int>& arr, int k) {
    return backtrack(arr, k, 0, 0);
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<findWays(arr,5);
    return 0;
}