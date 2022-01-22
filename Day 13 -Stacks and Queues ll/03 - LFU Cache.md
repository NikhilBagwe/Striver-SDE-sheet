## OPTIMAL :

1. get(key) -> gets the value of key if it exists or returns -1
2. put(key, value) :
   - Updates the value of key if present
   - OR inserts the key if not present
   - When the cache is full, it removes the LFU one.
   - IF there are multiple LFU elements i.e there is a tie, then removes the LRU one
   
### Put algo:
1. Check if the given key exists or not in keynode hashmap.
2. Check if the capacity of cache is full or not. 
3. If the key dosen't exists in keynode and there is still space in cache, insert the given key into freqlist to corresponding frequency '1' and insert new node in DLL using LRU cache logic i.e as first node in DLL after head.

```cpp
/*
eg: 
freq.
 1   -> {(1, 3) , (2, 5)} <- DLL
 2   -> {(3, 30)}
 
 from above example, (3, 30) has frequency of 2 and every DLL corresponding to freq. no. is a LRU cache
*/

struct Node{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        // frequency
        cnt = 1;
    }
};

// Doubly Linked List
struct List{
    // Stores length of DLL
    int size;
    Node *head;
    Node *tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    } 
    
    // Same as 'addNewNode' function from LRU cache
    void addFront(Node *node){
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    // Same as 'deleteNode' function from LRU cache
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
}

class LFUCache
{
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    // Max Capacity of cache
    int maxSizeCache;
    int minFreq; 
    int curSize; 
    
public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    
    void updateFreqListMap(Node *node) {
        // Delete the node from keynode map
        keyNode.erase(node->key); 
        // Delete the node from DLL of corresponding frequency
        freqListMap[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) { ---------------------- START HERE ----------------------------
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }

    /*
    1. If the node is present, get the node and store in a variable.
    2. Store it's value into 'val'
    3. Now the node will move to next DLL as its frequency is changed
    */
    int get(int key)
    {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1;
    }

    void put(int key, int value)
    {
        
    }
};

```
