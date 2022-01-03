## BRUTE - TC = O(n) + O(n) ,  Sc = O(n)

- Store all node values of LL into a vector
- Then simply check whether the vector is palindrome or not

```cpp
class Solution {
public:
    
    bool isPalindrome(ListNode* head) {
        ListNode *node = head;
        vector<int> nodes;
        
        while(node != NULL){
            nodes.push_back(node->val);
            node = node->next;
        }
        
        int s=0, e=nodes.size()-1;
        while(s <= e){
            if(nodes[s] == nodes[e]){
                s++;
                e--;
            }
            else return false;
        }
        
        return true;
    }
};
```

## OPTIMAL - TC = O(n/2)-find middle node + O(n/2)-reverse the LL + O(n/2)-compare the LL , SC = O(1)

- Find the middle node of the LL
- 1-> 2-> 3-> 3-> 2-> 1
- Now reverse the LL from next node of middle node
- 1-> 2-> 3-> 1-> 2-> 3
- Now start comparing from the head of LL with the reversed LL after middle node.

```cpp
class Solution {
public:
    ListNode *reverseList(ListNode *head){
        ListNode *prev = NULL, *next = NULL;
        
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        // Find middle of LL
        ListNode *slow = head, *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Slow will stand on the middle node. Reverse the LL from slow->next node
        slow->next = reverseList(slow->next);
        // Move slow to next node
        slow = slow->next;
        
        // Now compare the nodes from start and middle 
        while(slow != NULL){
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};
```






