//brute force approach will be this 
/*
but this approach will require to store the pair in the stack which is not efficient reuquired is storing only int val not a pair

then we implemented min stack in the O(1) which is good but we require the stack having only in elements with no pair and min function having O(1) Complexity  
*/
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            st.push({val,min(st.top().second,val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
       return st.top().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */