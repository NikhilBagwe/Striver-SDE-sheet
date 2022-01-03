### BRUTE

- Pick tail nodes indiviually and attach them to the head
- Do it for 'k' no. of times

### OPTIMAL - TC = O(n)-calculate length + O(n-(n%k))-traverse till breakpoint = O(n)

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        
        ListNode *cur = head;
        
        // Find the length of LL
        int len = 1;
        while(cur->next != NULL){
            cur = cur->next;
            len++;
        }
        
        // Connect the tail(cur) node to head node creating circular LL
        cur->next = head;
        
        // Reduce 'k' by removing the extra rotations 
        // eg: If len=5 of a LL and k=12, then on rotating the LL 5 times it will give us the same LL back. So we eliminate the extra rotations in this step
        k = k % len;
        // Find the breakpoint in circular LL
        k = len - k;
        
        // Now will start traversing from the original head of LL to which our 'cur' is pointing till breakpoint
        while(k--) cur = cur->next;
        
        // Now break the connection and make new head
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
```
