## BRUTE - TC = O(n*logn)-to insert elements into set + O(n) , SC = O(n)

- Hashset stores the unique elements
- Copy those elements back into original vector
- Return size of set as answer

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        
        // Store all elements into a hashset
        for(auto it : nums){
            st.insert(it);
        }
        
        // Copy elements of hashset back into vector 'nums'
        int i = 0;
        for(auto it : st){
            nums[i++] = it;
        }
        
        // return size of hashset
        return st.size();
    }
};
```
