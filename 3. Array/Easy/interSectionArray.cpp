#include <bits/stdc++.h> 
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> result = {};
	vector<int> visited(m,0);

	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i] == arr2[j] && visited[j]==0){
				result.push_back(arr1[i]);
				visited[j] = 1;
				break;
			}
			if(arr2[j]>arr1[i]){
				break;
			}
		}
	}
return result;

}

vector<int> findArrayIntersectionOptimal(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> result = {};
	int i = 0;
	int j = 0;

	while(i<n && j<m){
		if(arr1[i] < arr2[j]){	
			i++;
		}else if(arr1[i] > arr2[j]){
			j++;
		}else{
			result.push_back(arr1[i]);
			i++;
			j++;
		}
	}
return result;

}

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)    {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int i = 0 ;
        int j = 0 ;

        vector<int> res;
        while(i < nums1.size() && j< nums2.size()){
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
            else {
                if(res.size() == 0 || nums1[i] != res.back())
                    res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};


int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5,6,7,8};
    vector<int> intersectionArr = findArrayIntersectionOptimal(arr1,arr1.size(),arr2,arr2.size());
    for(int i=0;i<intersectionArr.size();i++){
        cout<<intersectionArr[i];
    }
}