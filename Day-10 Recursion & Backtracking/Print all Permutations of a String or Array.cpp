// BRUTE ============================================= TC = n! * n , SC = O(n) + O(n)  ========================================================================

// Here we use a hashmap to store whether we visited a certain element or not and a 'ds' array to store the current permutation so SC = O(n) + O(n)
// Since we are generating all permutations, the TC is n! and as we are iterating the array it takes more O(n) time.

void findPermutation(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
    // Base - when we reach end of the array 
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    
    // Iterate over the nums array 
    for(int i = 0; i < nums.size(); i++){
        // If the current element from nums is not marked/visited in Frequency array 
        if(!freq[i]){
          
            // PICK UP the element and mark it as visited in freq array 
            ds.push_back(nums[i]);
            freq[i] = 1;
            findPermutation(ds, nums, ans, freq);
            
            // Mark the element as unvisited and pop it out for further recursive calls
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main()
{
    vector<int> nums {1, 2, 3};
    
    vector<vector<int>> ans;
    vector<int> ds;
    // Frequency array - used like a Hashmap
    int freq[nums.size()] = {0};
    
    findPermutation(ds, nums, ans, freq);
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}


// OPTIMAL  ================================================ TC = n! * n =================================================================================================

/*
Intution:
 Reason behind swapping is that Every number should be at every particular index
*/

void findPermutation(int index, vector<int> &nums, vector<vector<int>> &ans){
    // Base - when we reach end of the array 
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    
    // Iterate over the nums array 
    for(int i = index; i < nums.size(); i++){
        // Swap the current element i.e at index with all elements of the array from 'i' to 'nums.size()-1'
        swap(nums[index], nums[i]);
        findPermutation(index+1, nums, ans);
        
        // Swap the elements back for further calls
        swap(nums[index], nums[i]);
    }
}

int main()
{
    vector<int> nums {1, 2, 3};
    
    vector<vector<int>> ans;
    
    findPermutation(0, nums, ans);
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}
