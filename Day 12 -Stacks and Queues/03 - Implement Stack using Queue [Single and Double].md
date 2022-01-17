## Stack using Two Queues - TC = O(n) , SC = O(2n) = O(n)

- Init 2 queues - q1 and q2
- q1 will store elements as 'Stack' and q2 is used to perform 'PUSH' operation

```cpp
#include<bits/stdc++.h>

class Stack {
	queue<int> q1;
  queue<int> q2;

   public:
    
    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return (q1.empty());
    }
	
    /* Push algo :
    1. Push the given element into q2.
    2. Then transfer all the elements from q1 to q2.
    3. Swap data from q1, q2.
    */
    void push(int element) {
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
	
    // Remove top element of q1.
    int pop() {
        if(q1.empty()) return -1;
        int popped = q1.front();
        q1.pop();
        return popped;
    }

    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
};
```
