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

## OPTIMAL - TC = O(n)+O(n)+O(n) , SC = O(1)

- Init 2 pointers to head - 'iter' and 'front'
- Traverse the LL and create a deep copy node of each node and insert it after the original node and do the necessary connections.
- Agian traverse LL from start and this time copy the random pointers of original nodes to deep nodes
- Separate the deep copy list from original list

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head, *front = head;
        
        // First step: make copy of each node and link them together side-by-side in a single list.
        while(iter != NULL){
            // Move 'front' to iter's next node
            front = iter->next;
            
            // Create the copy node and make the necessary connections
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            
            // Move 'iter' to where 'front' is
            iter = front;
        }
        
        // Second round: assign random pointers for the copy nodes.
        iter = head;
        
        while (iter != NULL) {
            if (iter->random != NULL) {
              // Copy iter's random ptr into deep copy node's random ptr
              iter->next->random = iter->random->next;
            }
            
            // Move 2 steps ahead, skipping the deep copy node
            iter = iter->next->next;
        } 
        
        // Third step: restore the original list, and extract the copy list.
        
        iter = head;
        // Points to Head of the deep copy list
        Node *pseudoHead = new Node(0);
        // To keep a track of tail node of deep copy list
        Node *copy = pseudoHead;

        while (iter != NULL) {
            // 'iter' points to original list head, so move front to next original node by moving it 2 steps
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;

            copy = copy -> next; 
            iter = front;
        }

        return pseudoHead->next;
    }
};

```












