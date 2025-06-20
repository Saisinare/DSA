#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
//brute force solution
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        map<Node*,Node*> nodes;
        while(temp!=nullptr){
            nodes[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        while(temp!=nullptr){
            auto n = nodes[temp->next];
            auto r = nodes[temp->random];

            if(n!=nullptr){
            nodes[temp]->next = n;
            }
            if(r!=nullptr){
            nodes[temp]->random = r; 
            }
            temp = temp->next;
        }
        return nodes[head];
    }
    /*
    T.C. O(n)
    S.C. O(2N)
    */

    //Optimal Solution 
        Node* copyRandomList(Node* head) {
        Node* temp = head;
        if(head == nullptr) return nullptr;
        while(temp!=nullptr){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=nullptr){
            if(temp->random!=nullptr){
            temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* copy = head->next;
        Node* copyHead = copy;
        Node* original = head;

        while(copy!=nullptr){
            original->next = original->next->next;
            if(copy->next!=nullptr){
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;

        }
        return copyHead;
    }

};

/*
T.C. O(N)
S.C O(1)
*/

