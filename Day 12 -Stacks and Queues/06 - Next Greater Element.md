## BRUTE - TC = O(n^2)

- Next Greater Element = An element that is greater than the current element and comes just after it.
- eg: arr = {2, 4, 1, 6, 9} . The NGE for arr[1]=4 is '6'. Here '9' is also greater than '4' but we have to consider the very next element in order.

```cpp
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans;
    
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                ans.push_back(arr[j]);
                flag = 1;
                break;
            }
        }
        
        // If NGE is not present, insert '-1'
        if(flag == 0) ans.push_back(-1);
    }
    
    return ans;
}
```

## OPTIMAL - TC = O(n) , SC = O(n) - Non circular array

### Intution - We use stack to maintain an increasing order of elements i.e from top to bottom in stack
- Start iterating from the last element of array.
- As we are not considering the array to be circular, there is no element that is greater than last element to its right, so insert '-1' into ans array and insert last element into stack when stack is empty
- Now move to 2nd last element and check :
1. If it is smaller than top element of stack, than insert top element of stack into 'ans' and insert 2nd last element into stack
2. If it is greater than, keep popping elements from stack until you find next greater element.
3. If stack becomes empty, insert '-1' into array as it is the current greatest element and insert it into stack.
- Keep doing same for rest of the elements in array

```cpp
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans;
    stack<int> st;
    
    for(int i = n-1; i >= 0; i--){
        // If stack is empty, push '-1' into ans array
        if(st.size() == 0){
            ans.push_back(-1);
        }
        
        // If stack's top element is greater than arr[i], push 'st.top()' into ans array
        else if(arr[i] < st.top()){
            ans.push_back(st.top());
        }
        
        // If arr[i] is greater than or equal to stack's top element
        else if(arr[i] >= st.top()){
            // Pop stack's element until it's empty or you find a greater element than arr[i]
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            
            // After popping, if stack is not empty, push its top element into ans array
            if(!st.empty()) ans.push_back(st.top());
            // If stack became empty, then push '-1' into 'ans' as arr[i] is current greatest element
            else ans.push_back(-1);
        }
        
        // Push arr[i] into stack
        st.push(arr[i]);
    }
    
    // As we started from last index of array, reverse 'ans' array
    reverse(ans.begin(),ans.end());
    return ans;
}
```
