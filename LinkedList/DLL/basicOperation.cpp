#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class MyLinkedList {
public:
    void printList(Node *&head){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    Node *insertNode(Node *&head,int val){
        Node *newNode = new Node(val);
        newNode->next = head;
        if(head!=nullptr){
            head ->prev = newNode;
        }
        head = newNode;
        return head;
    } 
    // Node *removeNode(Node *head,int val){

    // } 
    // Node *insertNode(Node *node){
        
    // } 
    
};
int main(){
    Node *head = new Node(10);
    MyLinkedList *dll = new MyLinkedList();
    dll->insertNode(head,15);
    dll->printList(head);
    return 0;
}