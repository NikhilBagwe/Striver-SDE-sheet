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
        if(l1==NULL){
            tail->next = l2;
        }
        else if(l2==NULL){
            tail->next = l1;
        }
        
        return dummy->next;
    }
};

```

## OPTIMAL - TC = O(n+m)  SC = O(1)

- The idea is to make 'l1' point to the smallest head node and 'l2' to greatest and keep traversing the 2 lists 
- When (l1 > l2) attach l1's previous node i.e stored in temp to 'l2' and swap(l1, l2)

```cpp
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        // Point l1 to the smallest head node and l2 to the greatest head node
        if(l1->val > l2->val) swap(l1, l2);
        
        // Store the new head of the merged sorted list i.e l1 in result
        ListNode *res = l1;
        
        while(l1 != NULL && l2 != NULL){
            // Stores the last sorted node
            ListNode *temp = NULL;
            
            // Until (l1 < l2) keep moving l1 by 1 and store the latest sorted node in temp 
            while(l1 != NULL && l1->val <= l2->val){
                //storing last sorted node
                temp = l1;
                l1 = l1->next;
            }
            
            // when (l1 > l2) i.e when you come out of while loop above, point temp->next to l2 and swap(l1, l2) i.e.
            // link previous sorted node with next larger node in list2
            temp->next = l2;
            swap(l1, l2);
        }
        
        return res;
    }
};
```
