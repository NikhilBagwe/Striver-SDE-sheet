// BRUTE ============ SAME AS Combination Sum - 1  with a small change  ===================================================================================

// Here we genearte all possible combinations and store only the unique combinations using 'set'

void findCombination(int ind, int target, vector<int> &nums, set<vector<int>> &ans, vector<int> &ds){
    // Base - when we reach the end of array and target becomes '0'
    if(ind == nums.size()){
        if(target == 0){
            ans.insert(ds);
        }
        return;
    }
    
    // Pick UP element - when element at that index is <= target
    if(nums[ind] <= target){
        ds.push_back(nums[ind]);
      
        // ONLY CHANGE required from 'Combination sum 1' is add "ind + 1", since we can't pick up the same element again -------------- CHANGE --------------------------
        findCombination(ind+1, target-nums[ind], nums, ans, ds);
        
        ds.pop_back();
    }
    
    // NOT PICK element
    findCombination(ind+1, target, nums, ans, ds);
}

int main()
{
    vector<int> nums {1, 1, 1, 2, 2};
    int target = 4;
    
    set<vector<int>> ans;
    vector<int> ds;
    
    findCombination(0, target, nums, ans, ds);

    for(auto it: ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
