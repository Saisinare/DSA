/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
     if(head==nullptr || head->next == nullptr)  return head;
        
        Node* ones = new Node(-1);
        Node* zeros =  new Node(-1) ;
        Node* tows =  new Node(-1);
        
        Node* onesHead = ones;
        Node* zerosHead =  zeros;
        Node* towsHead =  tows;
        
        Node*  temp = head;
        while(temp!=nullptr){
            if(temp->data == 0){
                zeros->next = temp;
                zeros = zeros->next;
            }
            else if(temp->data == 1){
                ones->next = temp;
                ones = ones->next;
            }
            else{
                tows->next = temp;
                tows = tows->next;
            }
            temp = temp->next;
        }
        zeros->next = (onesHead->next)? onesHead->next:towsHead->next;
        ones->next = towsHead->next;
        tows->next = nullptr;
        Node* newHead =  zerosHead->next;
        delete(zerosHead);
        delete(onesHead);
        delete(towsHead);
        return newHead;
}