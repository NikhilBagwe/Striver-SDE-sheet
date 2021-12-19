# BRUTE - TC = SC = O(n)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> ans;
        while(head != NULL){
            ans.push_back(head);
            head = head->next;
        }
        return ans[ans.size()/2];
    }
};
```

# OPTIMAL - TC = O(n)  SC = O(1)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *node = head;
        
        while(head != NULL){
            n++;
            head = head->next;
        }
        
        int mid = n/2;
        while(mid--){
            node = node->next;
        }
        
        return node;
};
```

# BETTER - TC = O(n/2) - Tortoise Hare Approach - Slow and fast pointer

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        
        // Check whether fast has reached the last node (fast->next != NULL) or has went beyond the last node (fast != NULL)
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
```
