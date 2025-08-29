//Problem Understanding 
    /*
        1. I have given the array of integers each integer represent the price of the stock at the last-i
        2. I have also given the integer which is the next of the last element of the array 
        3. I have to find that what is the span of the today i.e. how many days including today have stock price lesser than equal to the today's stock price 
    */
#include<bits/stdc++.h>

using namespace std;
class StockSpanner {
public:

    vector<int> res;
    StockSpanner() {
        res = {};
    }
    
    int next(int price) {
        res.push_back(price);
        int count = 1;
        for(int i =res.size()-2;i>=0;i--){
            if(res[i]<=price) count++;
            else break;
        }
        return count;
    }
};


//Time complexity : O(n^2)
//Space Ccomplextiy: O(N)