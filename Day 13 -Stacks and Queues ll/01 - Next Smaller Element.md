## BRUTE - TC = O(n^2) 

```cpp
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                ans.push_back(arr[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0) ans.push_back(-1);
    }
    
    return ans;
}
```

## OPTIMAL - TC = O(n) , SC = O(n)-at max, stack may contain 'n' elements

- Our approach is to traverse the array from right to left and for each array element we will first pop all such elements that are currently at the top of stack and having a value greater than or equal to the current element.
- Now we will set the Next Smaller Element as the element at the top of the stack if the stack is non-empty otherwise we will set it as -1. 
- Now we will push that element into the stack and move ahead.
### Intution - This algorithm works because whenever we push an element to the stack, we know its value is greater than every element present in the stack. As we visit an array element, we know that if it's value is less than any item in the stack, it must be smaller than the element at the top of the stack because it is the largest item of the stack. Therefore we need not to do any kind of searching on the stack and we can just consider the last item every time.

```cpp
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> st;
    
    // Since we are pushing '-1' into stack at first, the stack will never become empty as the given 'arr' contains positive elements only
    st.push(-1);
    
    for(int i = n-1; i >= 0; i--){
        // Pop all the elements from stack that are greater or equal to than arr[i]
        while(st.top() >= arr[i]){
            st.pop();
        }
        
        // After popping elements >=arr[i], the top element present in stack will be smaller than arr[i]
        ans[i] = st.top();
        
        // Pushing the current element into the stack.
        st.push(arr[i]);
    }
    
    return ans;
}
```
