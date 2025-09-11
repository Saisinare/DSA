//when we subtract 1 from N the rightmost '1' is turned off and all of the right bits 0.
//we use this filter to remove the '1' bit one by one and count it 
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ;
        while(n){
            n &= (n-1);
            count++;
        }   
        return count;  
    }
};