## BRUTE - TC = O(n*m) + (n*m)log(n*m) , SC = O(n*m)

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
