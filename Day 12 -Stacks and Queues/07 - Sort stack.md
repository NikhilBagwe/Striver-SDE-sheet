## Recurssive soln :

```cpp
void insert(stack<int> &st, int temp){
    if(st.empty() || temp >= st.top()){
        st.push(temp);
        return;
    }
    
    int val = st.top();
    st.pop();
    insert(st, temp);
    
    st.push(val);
    return;
}

void sortStack(stack<int> &st)
{
    // Base case - 1 element is always sorted
	  if(st.size() == 1) return;
    
    // Store the top element and than pop it and call sortStack() again
    int temp = st.top();
    st.pop();
    sortStack(st);
    
    // Insert the popped element back into stack
    insert(st, temp);
    return;
}
```
