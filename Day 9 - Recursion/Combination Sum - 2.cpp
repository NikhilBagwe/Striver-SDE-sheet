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

// OPTIMAL =========================================== TC = 2^n * k  , SC = k*x ===================================================================================

// TC = 2^n * k -> where k=average lenght of 'ds' array we are putting into 'ans'
// SC -> Assume 'x' are the number of combinations possible 

void findCombination(int ind, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
    // Base - when target becomes '0'
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    
    // loop from current 'index' i.e 'ind' to 'n-1' where n=size of arr
    for(int i = ind; i < nums.size(); i++){
        
        // Check to avoid picking up duplicate elements again
        // (i > ind) -> checks whether we are visiting the element for the 1st time or not
        if(i > ind && nums[i] == nums[i-1]) continue;
        
        if(nums[i] > target) break;
        
        // PICK UP the element
        ds.push_back(nums[i]);
        findCombination(i+1, target-nums[i], nums, ans, ds);
        
        ds.pop_back();
    }
}

int main()
{
    vector<int> nums {1, 1, 1, 2, 2};
    int target = 4;
    
    vector<vector<int>> ans;
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
