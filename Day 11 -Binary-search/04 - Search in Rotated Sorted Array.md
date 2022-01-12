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
