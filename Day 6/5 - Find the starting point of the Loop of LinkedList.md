## BRUTE - TC = O(n) , SC = O(n)

- Store all the nodes of LL in a hashSet
- If the current node is already present in hashset, means a loop is present thus return the current node.

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        unordered_set<ListNode*> st;
        
        while(head != NULL){
            // If the current node is already present in hashset, means a loop is present
            if(st.find(head) != st.end()) return head;
            st.insert(head);
            head = head->next;
        }
        
        return NULL;
    }
};
```
