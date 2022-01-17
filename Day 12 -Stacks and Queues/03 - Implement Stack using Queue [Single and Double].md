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

## Stack using One Queue - TC = O(n) , SC = O(n)

- Here while pushing a new element, after pushing the new element, we have to again push the 'size-1' elements back into the queue to maintain the data in LIFO format.

```cpp
class MyStack {
public:
    queue<int> q;
    
    /* Push algo :
    1. Push the element into q.
    2. Calculate the 'size' of queue.
    3. Then again push the top 'size-1' elements back into queue. This way the front/top element will be the
       
       latest pushed element.
    4. In this way, data is stored in LIFO format.
    */
    void push(int x) {
        q.push(x);
        int s = q.size();
        for(int i = 0; i < s-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int popped = q.front();
        q.pop();
        return popped;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return (q.empty());
    }
};
```
