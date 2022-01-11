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
