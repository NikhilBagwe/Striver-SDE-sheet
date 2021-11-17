// ========================= TC = Exponential -> To be more specific , TC is 2^n * k (k=size of 'ds' array we need to insert into the 'ans') ================================

void findCombination(int ind, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
    // Base - when we reach the end of array and target becomes '0'
    if(ind == nums.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        // 'return' statement must be written outside, as sometimes you may reach the end of array, but target may not have become '0'
        return;
    }
    
    // Pick UP element - when element at that index is <= target
    if(nums[ind] <= target){
        ds.push_back(nums[ind]);
        // Recurrsive call to pick up the same element again 
        findCombination(ind, target-nums[ind], nums, ans, ds);
        
        // Remove the element that you added into 'ds' above inorder to perform 'NOT PICK' operation
        ds.pop_back();
    }
    
    // NOT PICK element
    findCombination(ind+1, target, nums, ans, ds);
}

int main()
{
    vector<int> nums {2,3,5};
    int n = nums.size();
    int target = 8;
    
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
