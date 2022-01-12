## BRUTE - TC = (n+m)log(n+m) , SC = O(n+m)

- Store elements from both the array into an external array.
- Sort the array
- Find its median

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++) ans.push_back(nums1[i]);
        for(int i = 0; i < nums2.size(); i++) ans.push_back(nums2[i]);
        
        sort(ans.begin(), ans.end());
        
        int n = ans.size();
        double median = 0.0;
        
        // For odd length array, mid element is the median
        if(n % 2 != 0) median = ans[n/2];
        
        // For even length array, addition of mid and previous to mid element divided by 2 is median
        else{
            int mid = n/2;
            int val = ans[mid] + ans[mid-1];
            median = val/2.0;
        }
        
         return median;
    }
};
```

## BETTER - TC = SC = O(n1 + n2) - MergeSort

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0, k = 0;
        int result[n1 + n2];
        
        // Apply 'merge' step from mergesort
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]) result[k++] = nums1[i++];
            else result[k++] = nums2[j++];
        }
        
        while(i < n1) result[k++] = nums1[i++];
        while(j < n2) result[k++] = nums2[j++];
        
        // size of 'result' array
        int n = n1+n2;
        
        if(n % 2 != 0){
            return (double)result[n/2];
        }
        else{
            return ((double)result[(n/2)-1] + (double)result[n/2])/2;
        }
    }
};
```
