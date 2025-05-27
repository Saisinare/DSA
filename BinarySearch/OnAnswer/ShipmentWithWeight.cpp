
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int result = -1;
        int maxi = INT_MIN;
    
        for(int i =0;i<weights.size();i++){
            sum+= weights[i];
            if(weights[i]>maxi){
                maxi = weights[i];
            }
        }
        
            
        if(days ==1) return sum;
        for(int weight = maxi;weight<=sum;weight++){
            int temp = weight;
            int currentDay = 1;
            bool isValid = true;
            for(int i =0;i<weights.size();i++){
                temp -= weights[i];
                if(temp<0){
                    currentDay ++;
                    temp = weight-weights[i];
                }
                if(currentDay>days){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                result = weight;
                break; 
            }
        }
    return result;
    }

        int shipWithinDaysOptimal(vector<int>& weights, int days) {
        int sum = 0;
        int result = -1;
        int maxi = INT_MIN;
    
        for(int i =0;i<weights.size();i++){
            sum+= weights[i];
            if(weights[i]>maxi){
                maxi = weights[i];
            }
        }
        
            
        int high = sum;
        int low = maxi;
        while(low<=high){
            int mid = low+(high-low)/2;
            //checking if the weight is enough
            int temp = mid;
            int currentDays = 1;
            for(int i = 0;i<weights.size();i++){
                temp -= weights[i];
                if(temp<0){
                    currentDays++;
                    temp = mid - weights[i]; 
                }
                if(currentDays>days){
                    low = mid + 1;
                    break;
                }
            }
            if(currentDays<=days){
                result = mid;
                high = mid-1;
            }
        }
    return result;
    }

};

int main() {
    vector<int> weights = {3, 3, 3, 3, 3, 3};
    int days = 2;

    Solution solution;

    int resultBruteForce = solution.shipWithinDays(weights, days);
    int resultOptimal = solution.shipWithinDaysOptimal(weights, days);

    cout << "Brute-force result: " << resultBruteForce << endl;
    cout << "Optimal result: " << resultOptimal << endl;

    return 0;
}
