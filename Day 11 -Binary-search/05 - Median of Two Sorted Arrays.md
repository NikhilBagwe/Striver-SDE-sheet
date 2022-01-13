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

## OPTIMAL - TC = O(log(m,n)) , SC = O(1)

- Speciality of median is that it divides the array into 2 halfs, both halfs having equal no. of elements present in them.
- Now make cuts in both array such that (l1 <= r2) and (l2 <= r1).
- Until the above mentioned conditions are satisfied, keep moving the cuts 
- In order to find this cuts we will use binary search.
- In case of even size arrays - max(l1,l2) and min(r1,r2) will give you the required 2 numbers to find median.
- In case of diff. size arrays i.e odd - min(r1,r2) is the median and binary search must be applied on smaller size array to avoid out of bound error.

- Border cases : Check in code comments


```cpp
/*
- Border cases :

1. If r1 or r2 is absent, consider r1/r2 as 'INT_MAX'
   eg: 2 3 4 5|  <- r1 absent
       6 7|8
       
2. If l1 or l2 is absent, consider l1/l2 as 'INT_MIN' 
   eg: |2 3 4 5  <- l1 absent
       6 7|8
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        // When length are different than apply binary search on the shortest length array 
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        
        int low = 0, high = n-1;
        while(low <= high){
            // Initialize the cuts
            int cut1 = low + (high-low)/2;
            // cut2 = Total no. of required elements to form an array(eg: if addn of both array sizes is 8, then each array is of size - 4) - Already present elements
            int cut2 = ((n+m)/2) - cut1;
            
            // Initialize l1, r1, l2, r2 and also check for extreme cases for out of bound errors
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];

            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];
            
            // Check for binary search conditions
            if(l1 > r2) high=cut1-1;    // Shift cut towards left side

            else if(l2 > r1) low=cut1+1; // Shift cut towards right side

            // When both conditions are satisfied return the median as per the size of array
            else{
                if((n+m)%2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else{
                    return (min(r1, r2));
                }
            }
        }
        return 0.0;
    }
};

```








