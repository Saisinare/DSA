#include<bits/stdc++.h>
using namespace std;

 class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 //brute force approach 
Node* convertToList(vector<int> arr) 
{
	if(arr.size()==0) return nullptr;
	Node *head = new Node(arr[0]);
	Node *temp = head;

	for(int i =1;i<arr.size();i++){
		Node *newNode = new Node(arr[i]);
		temp->child = newNode; 
		temp = temp->child;
	}
	return head;
}

Node* flattenLinkedList(Node* head) 
{
	Node* temp = head;
	vector<int> arr;
	while(temp!=nullptr){ // O(N)
		Node* t1 = temp;
		while(t1!=nullptr){ //O(M)
			arr.push_back(t1->data);
			t1 = t1->child;
		}
		temp = temp->next;
	}
	sort(arr.begin(),arr.end()); //O(X LOG X); X =O(M*N)
	Node *newhead = convertToList(arr); //O(M*N)
	return newhead;
}
//O(M*N)+O(M*N)+O(M)+O(N)

//Optimal Solution 
Node* mergeList(Node* list1,Node* list2 ){
	Node* dummy = new Node(-1);
	Node* res = dummy;
	while(list1!=nullptr &&  list2!=nullptr){
		if(list1->data < list2->data){
			res->child = list1;
			res = res->child;
			list1 = list1->child;
		}else{
			res->child = list2;
			res = res->child;
			list2 = list2->child;
		}
	}
	while(list1){
		res->child = list1;
		res = res->child;
		list1 = list1->child;
	}
	while(list2){
		res->child = list2;
		res = res->child;
		list2 = list2->child;
	}
	res->child = nullptr;
	return dummy->child;
}
Node* sortList(Node* head) 
{
		if(head == nullptr || head->next == nullptr) return head;
		Node* newHead = sortList(head->next);
		Node* result = mergeList(head,newHead);
		return result;
}

Node* flattenLinkedList(Node* head) 
{
		return sortList(head);
}
/*
    sortList Runs for O(N) Times 
    mergeList Runs for O(L1.length()+L2.length) while assume m = L1 and L2 Length which means O(M+M) = O(2M)
    for each sortList mergeList is call which means O(N) * O(2M) = O(2MN)
*/