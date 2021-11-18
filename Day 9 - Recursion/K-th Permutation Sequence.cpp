// BRUTE ====================== Explained in detail in Day-10 Permutation question ========================================================================

void findKthPermutation(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int freq[]){
    if(nums.size() == ds.size()){
        ans.push_back(ds);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            freq[i] = 1;
            ds.push_back(nums[i]);
            findKthPermutation(nums, ds, ans, freq);
            
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main()
{
    vector<int> nums {1, 2, 3, 4};
    int k = 17;
    
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    
    findKthPermutation(nums, ds, ans, freq);

    vector<int> kthPermutation = ans[k-1];
    
    for(auto it : kthPermutation){
        cout<<it<<" ";
    }
    return 0;
}
