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
