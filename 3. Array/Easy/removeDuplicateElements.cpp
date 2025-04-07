#include <iostream>
#include <vector>
#include <set>

using namespace std;
int bruteRemove(vector<int> &arr)
{
    set<int> a;
    for (int i = 0; i < arr.size(); i++)
    {
        a.insert(arr[i]);
    }
    int index = 0;
    for (auto it : a)
    {
        arr[index] = it;
        index++;
    }
    return index;
}
int optimalRemove(vector<int> &nums)
{
       int i = 0; 
       for(int j=1;j<nums.size();j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
       } 
       return i+1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 3, 4};
    int size = optimalRemove(arr);
    cout << "" << size;
    return 0;
}