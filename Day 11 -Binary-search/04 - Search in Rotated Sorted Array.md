### PS - Search element in a sorted and rotated array/ find pivot where it is rotated

## BRUTE - TC = O(n)

- The idea is to find the pivot element i.e 'target' from where the array was rotated and return it's index.

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] == target) return i;
        }
        
        return -1;
    }
};
```

## OPTIMAL - TC = O(logn) , SC = O(1)

- Apply binary search, and try figuring out where the target/pivot element lies by decreasing the search space.
- For left half - Compare target with 'low' and 'mid' element to check whether target element lies there.
- For right half - Compare target with 'mid' and 'high' element to check whether target element lies there.

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        // eg: nums = {4,5,6,7,0,1,2,3}, target = 0
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(nums[mid] == target) return mid;
            
            // Check if left half is sorted
            if(nums[low] <= nums[mid]){
                // Figure out if the target element lies in left half or not 
                // eg : For 1st iteration :- Check '4 <= 0 <= 7' -> false
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            
            // Check if right half is sorted
            else{
                // Figure out if the target element lies in right half or not
                // eg: nums[mid] <= target <= nums[high]
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        
        return -1;
    }
};
```
