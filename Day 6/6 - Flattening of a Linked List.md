## OPTIMAL - TC = O(summation of nodes) , SC = Stack space

- Go to the last node of the LL using recursion
- Return from there
- Now you are on 2nd last node. Merge the 2nd last node LL and last node LL and return the merged LL.
- Keep repeating the above steps for rest of nodes.

```cpp
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
}; ----------------------------------------------------------------------------------
*/

Node *mergeTwoLists(Node *a, Node *b){
    Node *temp = new Node(0);
    // res will keep track of new sorted LL head
    Node *res = temp;
    
    while(a != NULL && b != NULL){
        if(a->data < b->data){
            // Attach 'a' node to temp's bottom
            temp->bottom = a;
            // Move temp and 'a' by 1
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    // Add the remaining nodes to LL
    if(a) temp->bottom = a;
    else temp->bottom = b;
    
    return res->bottom;
}

Node *flatten(Node *root)
{
   // Base case
   if(root == NULL || root->next == NULL){
       return root;
   }
   
   // Go to the last LL using recursion
   root->next = flatten(root->next);
   
   // now merge the last and second last LL
   root = mergeTwoLists(root, root->next);
   
   // Return the merged LL as root
   return root;
}
```
