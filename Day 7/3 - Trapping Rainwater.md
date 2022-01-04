## BRUTE - TC = O(n^2)

- Here we will find the leftmax and rightmax for every height and then calculate the amount water trapped.
- To find leftmax, we iterate from current position of 'i' backwards to 0th position of array.
- To find rightmax, we iterate from current position of 'i' towards to last element of array.

```cpp
class Solution {
public:
    int trap(vector<int>& arr) {
        int trappedWater = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            int j = i;
            int leftMax = 0, rightMax = 0;
            
            // Find leftMAx
            while(j >= 0){
                leftMax = max(leftMax, arr[j]);
                j--;
            }
            
            j = i;
            
            // Find rightMax
            while(j < n){
                rightMax = max(rightMax, arr[j]);
                j++;
            }
            
            // We will consider the minimum height as water is going to take level of that height and subtract the current height from it.
            trappedWater += min(leftMax, rightMax) - arr[i];
        }
        
        return trappedWater;
    }
};
```

## OPTIMAL - TC = O(n)+O(n)+O(n) =O(n) , SC = O(2n)

- Calculate the prefix and suffix array
- Then apply the same formula for 'trappedWater'
- Here we save the extra O(n) time used to calculate leftmax and rightmax for each index

```cpp
class Solution {
public:
    int trap(vector<int>& arr) {
        int trappedWater = 0;
        int n = arr.size();
        
        int prefix[n], suffix[n];
        
        // Calculating PREFIX array - stores max height from left to right
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(arr[i], prefix[i-1]);
        }
        
        // Calculating SUFFIX array - stores max height from right to left
        suffix[n-1] = arr[n-1];
        
        // Start from the 2nd last element as you have already considered the last element
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], arr[i]);
        }
        
        for(int i = 0; i < n; i++){
            trappedWater += min(prefix[i], suffix[i]) - arr[i];
        }
        
        return trappedWater;
    }
};
```









