## BRUTE - TC = O(n)+O(n) = O(2n)  ,  SC = O(1)

- Find the size of LL
- Then find the previous node to the node to be deleted by subtracting 'size - n - 1' 
- Now again traverse the LL upto 'x' node and make necessary connections and delete the required node

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge cases
        if(head->next == NULL || head == NULL) return NULL;
        
        ListNode *node = head;
        
        // Calculate size of LL
        int size = 0;
        while(node != NULL){
            size++;
            node = node->next;
        }
        
        // Find the node, previous to the node to be deleted
        int x = size-n-1;
        node = head;
        
        // Edge case - When you have to delete the head node
        if(size == n){
            ListNode *temp = head->next;
            delete head;
            return temp;
        }
        
        // Stand on the node, previous to the node to be deleted
        while(x--){
            node = node->next;
        }
        
        // Connections
        ListNode *temp = node->next->next;
        delete node->next;
        node->next = temp;
        
        return head;
    }
};
```
