## BRUTE - TC = SC = O(n) -> HASHING

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        // Push the whole node into map, not only it's value as there can be nodes with duplicate values present in LL
        unordered_map<ListNode*, int> mp;
        
        while(head != NULL){
            mp[head]++;
            
            // If node's count is 2, it means it appeared twice so cycle is detedted
            if(mp[head] > 1) return true;
            head = head->next;
        }
        
        return false;
    }
};
```

## OPTIMAL - TC = O(n) , SC = O(1) -> SLOW AND FAST POINTERS

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        
        ListNode *slow = head, *fast = head;
        
        // Check whether you are standing on tail node (fast->next != NULL) or on the second last node (fast->next->next != NULL)
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        
        return false;
    }
};
```
