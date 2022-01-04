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

## BETTER - TC = O(n) , SC = O(1)

- Init left and right pointers and leftmax = rightmax = 0
- Apply Two pointer approach
- Instead of creating 2 separate arrays for prefix and suffix, maintain leftmax and rightmax while traversing the array

```cpp
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        
        // Move until left ptr crosses right
        while(left <= right){
            
            // Intution - This check makes sure that there exists rightMax of greater size than current leftMax
            if(arr[left] <= arr[right]){
                // Update 'leftMax' value
                if(arr[left] >= leftMax){
                    leftMax = arr[left];
                }
                
                // Store the trapped water into 'res'
                else{
                    res += leftMax - arr[left];
                }
                
                left++;
            }
            
            // Intution - This check makes sure that there exists leftMax of greater size than current rightMax
            else{
                if(arr[right] >= rightMax){
                    rightMax = arr[right];
                }
                
                else{
                    res += rightMax - arr[right];
                }
                
                right--;
            }
        }
        
        return res;
    }
};

```

