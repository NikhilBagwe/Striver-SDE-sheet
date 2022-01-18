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
