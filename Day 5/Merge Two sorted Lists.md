## BRUTE - TC = SC = O(n+m) - Normal Merge sort

```cpp
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        
        // Init a dummy node & tail node-to keep track of the last node to which we have to append the new node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = new ListNode(0);
        
        // Assign the First smallest node to the dummy->next and then apply normal Merge sort
        if(l1->val < l2->val){
            ListNode* node = new ListNode(l1->val);
            l1 = l1->next;
            dummy->next = node;
            tail = node;
        }
        else{
            ListNode* node = new ListNode(l2->val);
            l2 = l2->next;
            dummy->next = node;
            tail = node;
        }
        
        // Merge sort
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                ListNode* node = new ListNode(l1->val);
                l1 = l1->next;
                tail->next = node;
                // move tail to the newly appended node
                tail = node;
            }
            else{
                ListNode* node = new ListNode(l2->val);
                l2 = l2->next;
                tail->next = node;
                tail = node;
            }
        }
        
        // Insert the remaining nodes if any directly
        while(l1!=NULL){
            ListNode* node = new ListNode(l1->val);
            l1 = l1->next;
            tail->next = node;
            tail = node;
        }
        while(l2!=NULL){
            ListNode* node = new ListNode(l2->val);
            l2 = l2->next;
            tail->next = node;
            tail = node;
        }
        
        return dummy->next;
    }
};

```
