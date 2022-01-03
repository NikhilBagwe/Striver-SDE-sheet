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

## OPTIMAL - TC = O(n) - Slow and fast pointer

- Find the node at which slow and fast pointers meet.
- Init a temp pointer pointing back to head.
- Then move the slow and temp ptr simultaneously until they meet. That will be the point of collision

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode *slow = head, *fast = head;
        
        // Find the node at which slow and fast ptrs meet
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        // If (fast == NULL || fast->next == NULL) means loop dosen't exist
        if(fast == NULL || fast->next == NULL) return NULL;
        
        // Init a ptr to head
        ListNode *temp = head;
        // Move the slow and temp ptr simultaneously until they met. That will be the point of collision
        while(slow != temp){
            temp = temp->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
```
