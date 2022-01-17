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

## Oueue using two stacks - Amortized O(1) solution

- TC = O(1) , SC = O(n)
- Here Push and Pop operations take O(1) time.
- Pop and Peek/top operation takes Amortized O(1) time meaning most of the times they take O(1) time but in certain conditions we transfer 'n' elements taking O(n) time.

```cpp
class MyQueue {
public:
    stack<int> input; // Input stack
    stack<int> output; // Output stack
    
    // Just push 'x' into 's1'.
    void push(int x) {
        input.push(x);
    }
    
    /* Pop algo :
    1. If 'output' stack is not empty, just pop it's top element.
    2. Else, transfer all elements from input to output stack and then pop output stack's top element.
    */
    int pop() {
        if(!output.empty()){
            int popped = output.top();
            output.pop();
            return popped;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            
            int popped = output.top();
            output.pop();
            return popped;
        }
    }
    
    // 1. If 'output' stack is not empty, just return it's top element.
    // 2. Else, transfer all elements from input to output stack and then return output stack's top element.
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            
            return output.top();
        }
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

```
