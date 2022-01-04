## BRUTE - TC = O(n) + O(n) , SC = O(n)

- Store all the nodes in a map corresponding to their deep copy node
- Now again iterate the LL from head and assign the deep copies their next and random pointer.

```cpp
/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr = head;
        map<Node*, Node*> m;
        
        // Store all th nodes corresponding to their deep copies in map
        while(ptr){
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        
        while(ptr){
            // Point the 'next' and 'random' of deep copy of current 'ptr' to 'ptr->next' & 'ptr->random' respectively
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        
        return m[head];
    }
};

```
