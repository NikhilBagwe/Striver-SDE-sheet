## BRUTE - TC = O(n^2) , SC = O(1)

```cpp
/*
Brute force :
1. Try finding area for every histogram possible. Consider the height of histogram as its length.
2. To find width, find the left smallest element and right smallest element to the current element 
   and that will give us the height.
   eg : arr = [2, 1, 5, 6, 2, 3, 1]
   For arr[4] = 2, the left smallest element = arr[1]=1 and right smallest element=arr[6]=1
   So width = 4
3. The formula to find area -> (right smaller - left smaller + 1) x arr[i]
   where, (right smaller - left smaller + 1) = Width (breadth)
   		  arr[i] = length
*/

int largestRectangle(vector < int > & arr) {
    int maxArea = 0;
    int n = arr.size();
    
    for(int i = 0; i < n; i++){
        int minHeight = INT_MAX;
        
        // Here we calculate maxArea for each element from 'i to j'
        // Find the right smallest element at 'j' and the left smallest element will be the current 'i'
        for (int j = i; j < n; j++) {
          minHeight = min(minHeight, arr[j]);
          maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    
    return maxArea;
}
```

------------------------------- OR -----------------------------------------------

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
        int n = arr.size();
        
        if(n == 1) return arr[0]*1;
        
        for(int i = 0; i < n; i++){
            int width = 1, cur = i+1;
            
            // Iterate on right side
            while(cur < n){
                if(arr[i] <= arr[cur]) width++;
                cur++;
            }
            
            // Iterate on left side
            if(i == 0){
                continue;
            }
            else{
                cur = i-1;
                while(cur >= 0){
                    if(arr[i] <= arr[cur]) width++;
                    cur--;
                }
            }
            
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
```
