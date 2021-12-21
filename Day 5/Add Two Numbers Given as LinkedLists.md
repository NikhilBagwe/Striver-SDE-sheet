## OPTIMAL - TC = O(max(l1, l2)) , SC = O(n)

- This has only optimal soln.
- TC = O(max(l1, l2)) as either we will traverse the LL1 or LL2 completely , so the maximum length of either LL will be TC
- ALGO
1. Init dummy node and temp node - to keep track of tail of new LL
2. On each iteration keep adding the node values pointed by l1, l2 and accordingly calculate carry and sum.
3. On calculating sum create 'node' containing 'sum%10' value

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        // Temp keeps track of tail node of new LL being formed
        ListNode *temp = dummy;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            
            // Store the addition of nodes pointed by 'l1' and 'l2' into sum
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            
            // If there was a carry from previous addition the add it
            sum += carry;
            // Store carry - eg:suppose sum=10, then carry=1 as '10/10=1'
            carry = sum/10;
            // Create new node
            ListNode *node = new ListNode(sum % 10);
            // Move temp by 1
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};

```
