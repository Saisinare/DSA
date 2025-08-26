#include<bits/stdc++.h>
#using namespace std;
//Direct Optimal 
    /*
        1. make an stack or an array with ans 
        2. loop through the asteroids array
        3. insert the positive element directly with no condition 
        4. if negative number occurs 
            1. while(we have the number which is positive and our abs negative val is greater than this element pop the element)
            2. if(their are elements remaining which is equal to the astestroids[i] and its sign is positive then ) remove that elemnt 
            3. else if(ans is empty or ans's last element is negative) insert the asetroid in ans.
    */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i =0;i<n;i++){
            if(asteroids[i]>0) ans.push_back(asteroids[i]);
            else{
                while(!ans.empty() && ans.back()>0 && ans.back() < abs( asteroids[i] ) ) ans.pop_back();
                if(!ans.empty() && ans.back() == abs(asteroids[i])) ans.pop_back();
                else if(ans.empty() || ans.back()<0) ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};

//O() T.C
//O() S.C