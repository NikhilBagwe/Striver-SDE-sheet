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

## OPTIMAL - TC = O(log(min(n,m))) , SC = O(1)

- We are applying binary search in the array with minimum size among the two. And we know the time complexity of the binary search is log(N) where N is the size of the array. Thus, the time complexity of this approach is log(min(n,m)), where m,n are the sizes of two arrays.

```cpp
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // Apply binary search on smaller array
        if(m < n) return kthElement(arr2, arr1, m, n, k);
        
        // This is done to avoid considering all elements from a single array only
        int low = max(0, k-m), high = min(k, n);
        
        while(low <= high){
            int cut1 = low + (high-low)/2;
            int cut2 = k - cut1;
            
            // Check if cut1/cut2 are present before 0th index of arrays
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            // Check if cut1/cut2 are present after last index of arrays
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            // Binary search conditions
            if(l1 > r2) high = cut1-1;
            else if(l2 > r1) low = cut1+1;
            else{
                return max(l1, l2);
            }
        }
        
        return 0;
    }
};
```
