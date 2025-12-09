#include <bits/stdc++.h> 
using namespace std;

void sortMyWay(stack<int> &stack,int ele){
	if(stack.empty() || stack.top()<ele){
		stack.push(ele);
		return;
	}
	int tp = stack.top();
	stack.pop();
	sortMyWay(stack,ele);
	stack.push(tp);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
	int ele =stack.top(); 
	stack.pop();
	sortStack(stack);
	sortMyWay(stack,ele);
}