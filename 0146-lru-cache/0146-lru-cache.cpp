class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;  //pointers
        node* prev;
        node(int _key, int _val){    //constructor //used for creating a new node;
            key = _key;
            val = _val;
        }
    };
    
    node * head = new node(-1,-1);             
    node * tail = new node(-1,-1);
    
    int cap;    //stores the total size of chache allowed
    unordered_map<int,node*>mp;
    
    
     void addnode(node* newnode){
        node* temp=head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
         
    }
    
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    
    LRUCache(int capacity) { //gives the capacity of LRU
        cap=capacity;
        head->next = tail;
        tail->next = head;
    }
    
    
    int get(int key_) { //return the value if exists else -1
        if(mp.find(key_) != mp.end()){
            node* naddress = mp[key_];
            int res = naddress->val;
            mp.erase(key_);
            deletenode(naddress);
            addnode(naddress); //adding right after the head
            mp[key_] = head->next; //new address for the key guy
            //reassigning
            
            return res;
        }
        return -1; // did not find it
    }
    
    void put(int key_, int value) {
        //put the key and value and push into the cache data structure
        //if size is full, the remove the least recently used guy and then insert
        
        if(mp.find(key_) != mp.end()){
            node* existingnode = mp[key_];
            mp.erase(key_);
            deletenode(existingnode);    
        }
        
        if(mp.size() == cap){
            mp.erase(tail->prev->key);      //erasing from tail as LRU
            deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        mp[key_]=head->next;
        
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */