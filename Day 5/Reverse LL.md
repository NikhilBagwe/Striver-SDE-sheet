# Iterative - 3 pointer

```cpp
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *prev=NULL, *cur=head, *next1=head->next;
        
        while(cur != NULL){
            cur->next = prev;
            prev = cur;
            cur = next1;
            if(next1 != NULL) next1 = next1->next;
        }
        
        return prev;
    }
};
```

# Recursive

```cpp
class Solution {
public:
    ListNode *reverse(ListNode *head){
        if(head->next == NULL){
            return head;
        }
        
        // Stores the new head of reversed LL i.e tail node of LL before reversing
        ListNode* reverseHead = reverse(head->next);
        
        // reverse connection
        head->next->next = head;
        // break connection
        head->next = NULL;
        
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        return reverse(head);
    }
};
```
