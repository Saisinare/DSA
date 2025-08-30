        //calculate the time to reach target for each car and then store it into the vector of pairs    
        //sort this vector in the decending order by their position
        //now maintain a stack and form a loop 
            //if stack is empty means the the new car is the new fleet insert it into the stack 
            //if new cars time_to_reach is greater than the st.top() which is the previous fleet than just add it to the fleet cause it is not going to catch up with previous car fleet so it is new fleet 
            //else all of this condition fails do nothing as if time_to_reach of the car is < st.top() then this car is going to probably merge with the previouse fleet so no need to insert it into stack 
            //now at the end return the size of the stack so we found the no. of fleets of the cars which is going to reach to the target location 
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        int n = position.size();
        for(int i =0;i<n;i++){
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i],time});
        }

        sort(cars.begin(),cars.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        stack<double> st;
        for(int i =0;i<n;i++){
            double time = (double)cars[i].second;
            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};