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

## OPTIMAL - TC = O(n) , SC = O(1)

- Two pointer approach
- Here we will point 'i' to 0th index of array and 'j' to 1st index
- Whenever 'j' will find a different element than the element pointed by 'i', we will move 'i' by 1 and assign it the element pointed by 'j'
- All elements before 'i' pointer will be unique so return 'i+1' as the total no. of unique elements

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int i = 0;
        
        // Start iterating from 1st index of array
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        
        // Total no. of unique elements
        return i+1;
    }
};
```
