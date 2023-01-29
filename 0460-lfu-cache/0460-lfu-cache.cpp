
    struct Node{
        int key,value,count;
        Node * next;
        Node* prev;
        Node(int _key,int _value){
            key = _key;
            value = _value;
            count = 1;
            
        }
    };
    
    struct List{
        int size;
        Node* head;
        Node* tail;
        List(){
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail-> prev = head;
            size = 0;
        }
    
        void addfront( Node * newnode)
        {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        size++;
        }
    
        void removenode(Node* delnode)
        {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
        }
    };
    
class LFUCache{
    map<int, Node*>keynode;
    map<int, List*>freqlist;
    int maxsizecache;
    int minfreq;
    int cursize;
  
public:
    LFUCache(int capacity) {
        maxsizecache=capacity;
        minfreq=0;
        cursize=0;
    }
    
    
    void updatefreqlist(Node *node){
        keynode.erase(node->key);
        freqlist[node->count]->removenode(node);
        if(node->count == minfreq && freqlist[node->count]->size == 0){
            minfreq++;
        }
        
        List* nexthigherfreqlist = new List();
        if(freqlist.find(node->count + 1) != freqlist.end()){
            nexthigherfreqlist = freqlist[node->count + 1];
        }
        
        node->count +=1;
        nexthigherfreqlist->addfront(node);
        freqlist[node->count] = nexthigherfreqlist;
        keynode[node->key] = node;
    }
    
    
    int get(int key) {
        //gets the value of key if exists else -1;
        if(keynode.find(key) != keynode.end()){  //if its present
            Node* node = keynode[key];          //node address
            int val = node->value;          //node's value
            updatefreqlist(node);           //update as per the freq
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        //update the value of key if exist, or insert if not exist
        //if the cache size is full, it removes the LFU guy and if it tie, then the LRU one will be selected.
        
        if(maxsizecache == 0){
            return;
        }
        
        if(keynode.find(key) != keynode.end()){
            Node * node = keynode[key];
            node->value = value;
            updatefreqlist(node);
        }
        else{
            if(cursize == maxsizecache){
                List* list = freqlist[minfreq];
                keynode.erase(list->tail->prev->key);
                freqlist[minfreq]->removenode(list->tail->prev);
                cursize--;
            }
            
        cursize++;
             // new value has to be added who is not there previously 
            minfreq = 1;
            List* listfreq = new List();
            if(freqlist.find(minfreq) != freqlist.end()){
                listfreq = freqlist[minfreq];
            }
            Node* node = new Node(key, value);
            listfreq->addfront(node);
            keynode[key] = node;
            freqlist[minfreq] = listfreq;
        }
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */