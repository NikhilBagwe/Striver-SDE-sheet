## BRUTE - TC = O(n^2) , SC = O(n)

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
