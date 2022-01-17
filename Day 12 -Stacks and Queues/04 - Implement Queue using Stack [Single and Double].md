## Queue using Two Stacks - TC = O(n) , SC = O(2n)

```cpp
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    /* Push algo :
    1. Transfer all elements from s1 to s2.
    2. Then push given element 'x' into s1.
    3. Then again transfer elements from s2 back to s1.
    */
    void push(int x) {
        // 1. s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        // 2. Push 'x' in s1
        s1.push(x);
        
        // 3. s2 -> s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.empty()) return -1;
        int popped = s1.top();
        s1.pop();
        return popped;
    }
    
    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return (s1.empty());
    }
};
```
