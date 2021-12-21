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

## OPTIMAL - TC = O(n)  ,  SC = O(1)

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Init dummy node and point it's 'next' to head
        ListNode *dummy = new ListNode();
        dummy->next = head;
        // Init slow anf fast ptr and point them to dummy
        ListNode *slow = dummy, *fast = dummy;
        
        // Move fast ptr by 'n' steps
        while(n--){
            fast = fast->next;
        }
        
        // Move fast and slow ptrs until (fast->next != NULL)
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        // Slow will be standing on the previous node of the node to be deleted so make required connections
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
```
