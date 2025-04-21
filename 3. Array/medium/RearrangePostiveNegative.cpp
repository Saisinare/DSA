#include <bits/stdc++.h> 
using namespace std ;
void rearrange(vector<int> &arr)
{
	vector<int> pos ;
	vector<int> neg ;
	int n = arr.size();
	vector<int> result(n,0);
	for(int i=0;i<arr.size();i++){
		if(arr[i] >0){
			pos.push_back(arr[i]);
		}		
		else if(arr[i] <0){
			neg.push_back(arr[i]);
		}
	}

	if(pos.size()<neg.size()){
		for(int i =0;i<pos.size();i++){
			arr[i*2+1] = pos[i];
			arr[i*2] = neg[i];
		}
		int index = pos.size()*2;
		for(int i = pos.size();i<neg.size();i++){
			arr[index] = neg[i];
			index++;
		}
	}else{
		for(int i =0;i<neg.size();i++){
			arr[i*2+1] = pos[i];
			arr[i*2] = neg[i];
		}
		int index = neg.size()*2;
		for(int i = neg.size();i<pos.size();i++){
			arr[index] = pos[i];
			index++;
		}
	}
	
}
// when even and odd numbers are not same size then optimal will not work and brut will be the optimal solution for that 
vector<int> rearrangOptimal(vector<int> &arr)
{
    int posIndex = 0;
    int negIndex = 1;
    int n = arr.size();
    vector<int> result(n,0);
    for(int i = 0 ;i<arr.size();i++){
        if(arr[i] < 0){
            result[negIndex] = arr[i];
            negIndex+=2;
        }
        else if(arr[i] > 0){
            result[posIndex] = arr[i];
            posIndex+=2;
        }
    }
    return result;
}
int main() {
    vector<int> arr = {3, -2, -5, 6, -7, 4, -1, 8};

    cout << "Original Array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    vector<int> arr1 = arr;
    rearrange(arr1);
    cout << "After rearrange(): ";
    for(int num : arr1) cout << num << " ";
    cout << endl;

    vector<int> result = rearrangOptimal(arr);
    cout << "After rearrangOptimal(): ";
    for(int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
