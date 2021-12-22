## OPTIMAL - TC = O(n)

```cpp
class Solution {
public:
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *p = NULL, *cur = s, *nex = s->next;
        
        while(p != e){
            cur->next = p;
            p = cur; 
            cur = nex;
            if(nex != NULL) nex = nex->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // beforeStart - points to dummy node, tail - keeps track of last node 
        ListNode *beforeStart = dummy, *e = head;
        
        int i = 0;
        
        while(e != NULL){
            i++;
            
            if(i%k == 0){
                ListNode *s = beforeStart->next, *temp = e->next;
                reverse(s, e);
                
                // On reversing, (s, e) = (e, s)
                beforeStart->next = e;
                s->next = temp;
                
                // Increment pointers for next iteration of kth group
                beforeStart = s;
                e = temp;
            }
            else{
                e = e->next;
            }
        }
        
        return dummy->next;
    }
};

```
