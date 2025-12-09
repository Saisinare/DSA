#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &stack,int ele){
    if(stack.empty()){
        stack.push(ele);
        return;
    }else{
        int tp = stack.top(); 
        stack.pop();
        insertAtBottom(stack,ele);
        stack.push(tp);
    }
}

void reverseStack(stack<int> &stack) {
    if (stack.empty()){
        return;
    }
    int ele = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,ele);
}
