## BRUTE - TC = O(n x m) + (n x m)log(n x m) , SC = O(n*m)

- In TC, n = no. of rows, m = column
- Store all the elements of matrix into an array
- Sort that array
- Return the array's mid element

```cpp
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> ans;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans[ans.size()/2];
    }
};
```

## OPTIMAL - TC = log(range)x(number of rows)xlog(column)

```cpp
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // We consider the constraints given in question as our search space
        int low = 0, high = 2000, mid = 0;
        // No. of elements in matrix
        int n = r*c;
        
        while(low <= high){
            mid = (low+high)/2;
            // Store no. of elements that are <=mid in each row
            int ans = 0;
            
            // Apply binary search on each row
            for(int i=0; i<r; i++){
                int l=0, h=c-1;
                
                while(l <= h){
                    // this formula is used to apply binary search on index instead of applying it on numbers present on those index
                    int m = l+(h-l)/2;
                    
                    if(matrix[i][m] <= mid) l = m+1;
                    else h=m-1;
                }
                
                ans += l;
            }
            
            if(ans <= n/2) low = mid+1;
            else high = mid-1;
        }
        
        return low;
    }
};
```
