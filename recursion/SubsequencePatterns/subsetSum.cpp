#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &num,int sum,vector<int> &current,vector<int> &result,int index){
	if(index==num.size()){
		result.push_back(sum);
		return;
	}

	current.push_back(num[index]);
	backtrack(num,sum+num[index],current,result,index+1);
	current.pop_back();	
	backtrack(num,sum,current,result,index+1);
}
vector<int> subsetSum(vector<int> &num){
    vector<int> result;
    vector<int> current;
    backtrack(num, 0, current, result, 0);
	sort(result.begin(),result.end());
    return result;
}
