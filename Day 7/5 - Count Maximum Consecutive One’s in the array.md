## OPTIMAL - TC = O(n) , SC = O(1)

- ones = keeps track of count of current consecutive 1's
- maxones = stores the max count of consective 1's throughout the array

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, maxones = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                ones += 1;
                if(ones > maxones) maxones = ones;
            }
            
            // When number at current index is != 1, the current streak of consective 1's is broken so reset the counter back to 0
            else{
                ones = 0;
            }
        }
        
        return maxones;
    }
};
```
