#include<bits/stdc++.h>
using namespace std;


  class Node {
  public:
       int data;
       Node *prev;
       Node *next;
      Node() {
          this->data = 0;
           this->prev = NULL;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->prev = NULL;
           this->next = NULL;
       }
       Node (int data, Node *next, Node *prev) {
           this -> data = data;
           this -> prev = prev;
           this -> next = next;
       }
  };

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> result;
    Node* front = head;
    Node* back = head;
    while(back->next !=nullptr){
        back  = back->next;
    }
    while((front->data)<(back->data) ){
        int sum = front->data + back->data;
        if(sum == k){
            result.push_back({front->data,back->data});
            back = back->prev;
            front = front->next;
        }
        else if(sum>k){
            back = back->prev;
        }else{
            front = front->next;
        }
    }
    return result;
}
