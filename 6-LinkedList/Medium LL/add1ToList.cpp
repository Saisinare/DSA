/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *revList(Node *head){
    if(head==nullptr || head->next==nullptr) return head;
            Node* newHead = revList(head->next);
            Node* front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
}
Node *addOne(Node *head)
{
    Node *newHead = revList(head);
    int carry = 1;
    Node *temp = newHead;
    while(temp!=nullptr){
        if((temp->data+carry)>=10){
            temp->data = (temp->data+carry)%10; 
        }else{
            temp->data += carry;
            carry = 0;
            break;
        }
        temp = temp->next;
    }
    newHead = revList(newHead);
    if(carry==1 && temp==nullptr){
        Node* newNode = new Node(1);
        newNode->next = newHead;
        return newNode;
    }
    return newHead;
}

//T.C:- O(n)
//we cannot move backwards cause we need reversed pointer but without reversing the pointers we need backtraking 

int adding(Node *head){
    if(head==nullptr) return 1;
    int carry= adding(head->next);
    head->data += carry;
    if(head->data<10) return 0;
    head->data = 0;
    return 1; 
}
Node *addOne(Node *head)
{
    int carry = adding(head);
    if(carry==1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    
    return head;
}
