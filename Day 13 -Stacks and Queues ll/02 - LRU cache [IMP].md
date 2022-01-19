## OPTIMAL : TC = O(1)-In very rare cases when there are collisons in map, its O(n) , SC = O(1)

- "Least Recently Used" means suppose you have 4 T-shirts. You wear 1st T-shirt on Monday, 2nd on tue, 3rd on wed and 4th on thu. So here the least recently used is 1st 
  T-shirt that you wore on monday as 4th is the "Most recently used" T-shirt.
- Here we use a Doubly LL and Hash map to implement LRU cache.
- In code, whenever a action is performed whether its get or put, the node on which action is performed becomes 'Most recently used' node so attach it next after head node.
- At times when the capacity of LRU cache becomes full, we remove the 'Least Recently used' node which is the node present before tail node.

```cpp
class LRUCache
{
public:
    class node{
        public:
        	int key;
        	int val;
        	node *next;
        	node *prev;
        
        	node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };
    
    // Init the head and tail for DLL
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    // New node is always added next to head node as it is 'Most Recently used' node
    void addnode(node *newNode){
        // Store the node present just after head
        node *temp = head->next;
        // Insert the newNode
        newNode->next = temp;
        newNode->prev = head;
        // Point head & temp node to newly inserted newNode
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deletenode(node *delNode){
        // Store the next and prev nodes of node to be deleted
        node *delnext = delNode->next;
        node *delprev = delNode->prev;
        // Make connection between next and prev nodes of 'delNode' thus deleting it
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    /* Algo :
    1. Check if the node exists or not in hashmap.
    2. If node exists, then store it in a temporary node 'resnode' as we have to return its value
    3. Erase it from hashmap.
    4. Now since this node is used recently as 'get' operation is performed on it, we have to delete 
       it and add it back after head node
    5. Store its new address into map
    6. If node dosent exists in map, return -1
    */
    int get(int key)
    {
        if(m.find(key) != m.end()){
            node *resNode = m[key];
            int res = resNode->val;
            m.erase(key);
            deletenode(resNode);
            addnode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    /* Algo :
    1. If the node with given 'key' exists, delete it as we are going to add it again.
    2. If capacity of LRU is fulled, delete "Least recently Used node" which is present just before 'tail' node
    3. Add the given node .
    */
    void put(int key, int value)
    {
        if(m.find(key) != m.end()){
            node *existingNode = m[key];
            m.erase(key);
            deletenode(existingNode);
        }
        
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key, value));
        m[key] = head->next;
    }
};
```
