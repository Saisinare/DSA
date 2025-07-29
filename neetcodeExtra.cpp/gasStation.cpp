class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totCost = 0, totGas =0;

        int start = 0,current=0; 
        for(int i =0;i<gas.size();i++){
            totCost += cost[i];
            totGas += gas[i];
            current += (gas[i]-cost[i]);
            if(current<0) {
                start = i+1;
                current =0;
            }
        }
        return (totGas<totCost)?-1:start;
    }
};