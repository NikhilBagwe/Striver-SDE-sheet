### Problem statement - Find the element that appears once in a sorted array, and the rest element appears twice 

## BRUTE - TC = O(n) , SC = O(n)

- Store all elements into a map
- Iterate the map again to check which element's frequency is less than 2 and return it.

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]] < 2) return nums[i];
        }
        
        return 0;
    }
};
```

## BETTER - TC = O(n) , SC = O(1)

- XOR all the elements of array linearly.
- Rules of XOR : x^0 = x , x^x = 0
- On iterating you will get the result of xoring - the number appearing only once
- eg: arr = {1,1,2,3,3,4,4,8,8}
- 0^1 = 1
- 1^1 = 0
- 0^2 = 2
- 2^3 = 1
- 1^3 = 2
- 2^4 = 6
- 6^4 = 2
- 2^8 = 10
- 10^8 = 2

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        
        for(int i=0; i < n; i++){
            num = num ^ nums[i];
        }
        
        return num;
    }
};
```

## OPTIMAL - TC = O(logn) , SC = O(1)

- On executing this algorithm, the 'low' pointer will be pointing to the single element i.e 'Breakpoint' and 'high' will be pointing to previous element og 'low'
- The single element will divide the whole array into left half and right half
- Now in this left array, the first instance of every element is occurring on the even index and the second instance on the odd index. 
- Similarly in the right array, the first instance of every element is occurring on the odd index and the second index is occurring on the even index.
- The intuition is that when we see an element, if we know its index and whether it is the first instance or the second instance, we can decide whether we are presently in the  left array or right array and accordingly shrink the search space to reach breakpoint.

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0;
        // Point 'high' to the 2nd last index, as if the single element is present on the last index, then our 'low' 
        // pointer will ultimately point to last element on shrinking
        int high = n-2;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            // For EVEN index
            if(mid % 2 == 0){
                // Check if we are in right half
                if(nums[mid] != nums[mid+1]){
                    // If we are, then shrink right half
                    high = mid-1;
                }
                else{
                    // If we are in left half, then shrink it
                    low = mid+1;
                }
            }
            
            // For ODD index
            else{
                // Check if we are in right half
                if(nums[mid] == nums[mid+1]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return nums[low];
    }
};
```








