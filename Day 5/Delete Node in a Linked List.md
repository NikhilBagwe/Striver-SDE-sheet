## OPTIMAL - TC = O(1)

- Head is not given and reference to node to be deleted is given.

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        // When tail node is to be deleted
        if(node->next == NULL) delete node;
        
        // Swap values
        swap(node->val, node->next->val);
        // Store the next node containing the value of the node to be deleted
        ListNode* temp = node->next;
        // Make required connection
        node->next = node->next->next;
        // Delete temp
        delete temp;
    }
};
```
