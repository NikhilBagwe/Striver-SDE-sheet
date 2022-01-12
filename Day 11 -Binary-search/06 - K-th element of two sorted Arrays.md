## BRUTE - TC = (n+m)log(n+m) , SC = O(n+m)

```cpp
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> ans;
        
        for(int i = 0; i < n; i++) ans.push_back(arr1[i]);
        for(int i = 0; i < m; i++) ans.push_back(arr2[i]);
        
        sort(ans.begin(), ans.end());
        
        return ans[k-1];
    }
};
```

## BETTER - TC = O(k)-We iterate at total k times  ,  OC = O(1) 

- Apply mergesort logic
- Instead of storing elements into an external array, initialize a counter and check when we reach kth element with help of it

```cpp
 class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0, j = 0, counter = 0, ans = 0;
        
        while(i < n && j < m){
            // When 'counter == k' return the answer
            if(counter == k) break;
            
            if(arr1[i] < arr2[j]){
                ans = arr1[i++];
            }
            else{
                ans = arr2[j++];
            }
            
            counter++;
        }
        
        // When arrays are of diff. size and smaller size array gets exhausted early
        if(counter != k){
            // Check if 'i' ptr has reached arr1's last element or not
            if(i != n-1){
                ans = arr1[k-counter];
            }
            else{
                ans = arr2[k-counter];
            }
        }
        
        return ans;
    }
};
```
