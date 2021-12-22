## BRUTE - TC = O(n x m) where n and m are length of the LLs

- Stand on the head of any LL suppose LL1 and compare for each node of LL1 with all nodes of LL2 that whether a node of LL1 is also present in LL2.
- That is the intersection point.

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        
        // For each node of l1, compare it with all nodes of l2.
        while(l1 != NULL){
            while(l2 != NULL){
                // If both nodes are same for l1 and l2, that is the intersection point
                if(l1 == l2) return l1;
                l2 = l2->next;
            }
            // Move l1 by 1 step
            l1 = l1->next;
            // Point l2 back to start of LL2
            l2 = headB;
        }
        return NULL;
    }
};

```

## OPTIMAL - TC = O(n + m) , SC = O(n)

- Hashing - Store all nodes of LL1 in hashmap and then iterate LL2 to find a similar node which will be the intersection point.

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        
        // Store all the nodes of LL1 in hashmap
        unordered_map<ListNode*, int> mp;
        while(l1 != NULL){
            mp[l1]++;
            l1 = l1->next;
        }
        
        // Now iterate LL2 and check for each node of LL2 whether it is present in hashmap
        while(l2 != NULL){
            if(mp.find(l2) != mp.end()) return l2;
            l2 = l2->next;
        }
        
        return NULL;
    }
};
```

## BETTER - TC = O(2m) , SC = O(1)

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Init 2 dummy pointers pointing to head of both LLs
        ListNode *d1 = headA, *d2 = headB;
        
        while(d1 != d2){
            // If 'd1' reached the end of LL1, point it to head of LL2
            if(d1 == NULL) d1 = headB;
            else d1 = d1->next;
            
            // If 'd2' reached the end of LL2, point it to head of LL1
            if(d2 == NULL) d2 = headA;
            else d2 = d2->next;
        }
        
        return d1;
    }
};
```
