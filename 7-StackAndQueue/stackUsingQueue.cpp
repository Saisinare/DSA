// Time Complexity:
//   push: O(n)
//   pop, top, empty: O(1)
// Space Complexity: O(n), where n is the number of elements in the stack.
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) { //O(N)
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {//O(1)
        int data = q1.front();
        q1.pop();
        return data;
    }
    
    int top() {//O(1)
        return q1.front();
    }
    
    bool empty() {//O(1)
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */