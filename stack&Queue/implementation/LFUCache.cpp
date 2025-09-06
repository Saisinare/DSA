class LFUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        int freq;
        Node(int key, int val){
            this-> key = key;
            this-> val = val;
            this->freq = 1;
            this->next = nullptr ;
            this->prev = nullptr ;
        }
    };

    struct DLL {
        Node* head;
        Node* tail;
        int size;
        DLL(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head -> next = tail;
            tail -> prev = head;
            size = 0;
        }
        void insertAtFront(Node* node){
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
            size++;
        }
        void removeNode(Node* node){
            node->next->prev = node->prev;
            node->prev->next = node->next;
            size--;
        }
        Node* removeFromLast(){
            if(size>0){
                Node* node = tail->prev;
                removeNode(node);
                return node;
            }
            return nullptr;
        }
    };

    int cap ;
    int minFreq;
    map<int,Node*> keyNode;
    map<int,DLL*> freqList;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        keyNode.clear();
        freqList.clear();
    }
    
    void updateFreq(Node* node){
        int freq = node->freq;
        freqList[freq]->removeNode(node);

        //if we remove the node from freqlist and it become empty and this freq is minimum freq then we have to udpate minfreq;
        if(freq==minFreq && freqList[freq]->size == 0 ){
            minFreq++; 
        }
        //increase the freq of node struct
        node->freq++;

        //if we don't find the freq inside the freqList create new one with new node freq
        if(freqList.find(node->freq)==freqList.end()){
            freqList[node->freq] = new DLL();
        }
        freqList[node->freq]->insertAtFront(node);
    }

    int get(int key) {
        if(cap==0 || keyNode.find(key)==keyNode.end()){
            return -1;
        }
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap==0) return ; // we cannot do anything 
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        }else{
            if(keyNode.size()==cap){
                Node* node = freqList[minFreq]->removeFromLast();
                keyNode.erase(node->key);
                delete node;
            }

            Node* node = new Node(key,value);
            minFreq = 1;
            if(freqList.find(minFreq) == freqList.end()){
                freqList[minFreq] = new DLL();
            }
            freqList[minFreq] -> insertAtFront(node);
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */