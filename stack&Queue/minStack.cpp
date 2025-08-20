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

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if(val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini); // encode
                mini = val;
            }
        }
    }

    void pop() {
        if(st.empty()) return;
        long long n = st.top();
        st.pop();
        if(n < mini) {
            // n was encoded, restore previous min
            mini = 2 * mini - n;
        }
        if(st.empty()) mini = LLONG_MAX; // reset if empty
    }

    int top() {
        if(st.empty()) return -1;
        long long n = st.top();
        if(n >= mini) return (int)n;
        else return (int)mini; // encoded marker → actual top is current min
    }

    int getMin() {
        return (int)mini;
    }
};

//optimal solution without using pair in stack 
//eachc operation usage O(1) complexity
