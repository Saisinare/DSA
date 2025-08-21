class MyQueue {
public:
    stack<int> s1;  // Primary stack to store queue elements
    stack<int> s2;  // Helper stack used during push operation
    
    MyQueue() {
        // Constructor (nothing special to initialize here)
    }
    
    // Function to insert element into queue
    void push(int x) {
        // Step 1: Move all elements from s1 to s2
        // This clears s1 so that new element can be pushed at the "bottom"
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        // Step 2: Push the new element into s1
        s1.push(x);
        
        // Step 3: Move everything back from s2 to s1
        // This ensures the new element stays at the bottom of s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // Function to remove element from front of queue
    int pop() {
        // Since s1 stores elements in queue order,
        // top of s1 is the front of the queue
        int data = s1.top();
        s1.pop();
        return data;
    }
    
    // Function to get front element without removing
    int peek() {
        // Return front of queue (top of s1)
        return s1.top();
    }
    
    // Check if queue is empty
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);      // Add element at back of queue
 * int param_2 = obj->pop();   // Remove front element
 * int param_3 = obj->peek();  // Get front element
 * bool param_4 = obj->empty(); // Check if queue is empty
 */
