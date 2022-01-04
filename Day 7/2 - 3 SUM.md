## BRUTE - TC = O(n^3)

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    temp.clear();
                    
                    if(arr[i] + arr[j] + arr[k] == 0){
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                    }
                    
                    if(temp.size() != 0){
                        ans.push_back(temp);
                    }
                }
            }
        }
        
        return ans;
    }
}
```

## OPTIMAL - TC = O(n^2)

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // As our 'i' pointer can only move upto 3rd last index only, we write (n-2)
        for(int i = 0; i < n-2; i++){
            
            // If 'i' is standing on the 1st element OR the current element is not same as previous element
            if(i == 0 || (i > 0 && arr[i] != arr[i-1])){
                
                // TWO POINTER
                int s = i+1, e = n-1, sum = 0-arr[i];
                
                while(s < e){
                    if(arr[s] + arr[e] == sum){
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[s]);
                        temp.push_back(arr[e]);
                        ans.push_back(temp);
                        
                        // Skip the duplicate numbers
                        while(s < e && arr[s] == arr[s+1]) s++;
                        while(s < e && arr[e] == arr[e-1]) e--;
                        
                        s++;
                        e--;
                    }
                    
                    else if(arr[s] + arr[e] < sum) s++;
                    
                    else e--;
                }
            }
        }
        
        return ans;
        
    }
};
```
