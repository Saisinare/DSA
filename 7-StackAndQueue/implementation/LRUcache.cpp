// LRU Cache

// 1.	maintain a doubly linked list and HashMap
// 2.	put(key,value) : if element not exists in the hashmap insert the element at the end of the list just before the tail
// 3.	get(key) : if element exists delete the element and add at the front and return its value if not exists return -1
// 4.	put(key,value) : if element does exists with key in the hashmap then delete from the current place replace its value with new and insert it in the front of the list
// 5.	after the put () if the element does not exists and length of list is greater than the capacity then just delete the last element

//each function is going to require the O(1) Complexity and the S.C = O(2N)
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    struct Node{
        int key,val;
        Node* next;
        Node* prev;
        Node(int key_, int val_){
            key = key_;
            val = val_;
            next = nullptr;
            prev = nullptr;
        }
    };
    map<int, Node*> mapp;
    Node* head;
    Node* tail;
    int cap;

    void removeNode(Node* node){
        node -> next -> prev = node->prev;
        node -> prev -> next = node->next;
    }

    void addToFront(Node* node){
        head -> next -> prev = node;
        node -> next = head ->next;
        head -> next = node;
        node -> prev = head;
    }

    LRUCache(int capacity) {
        mapp.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mapp.find(key)!=mapp.end()){
            Node* node = mapp[key];
            removeNode(node);
            addToFront(node);
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            Node* node = mapp[key];
            node -> val = value;
            removeNode(node);
            addToFront(node);
        }else{
            if(mapp.size()==cap){
                Node* node = tail->prev;
                mapp.erase(node->key);
                removeNode(node);
            }

            Node* node = new Node(key,value);
            addToFront(node);
            mapp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */