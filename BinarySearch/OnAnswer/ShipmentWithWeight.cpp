
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
};

int main() {
    // Example input
    vector<int> weights = {3, 3, 3, 3, 3, 3};
    int days = 2;
    
    // Create an object of the Solution class
    Solution solution;
    
    // Call the shipWithinDays method and store the result
    int result = solution.shipWithinDays(weights, days);
    
    // Output the result
    cout << "Minimum ship capacity to ship within " << days << " days is: " << result << endl;
    
    return 0;
}
