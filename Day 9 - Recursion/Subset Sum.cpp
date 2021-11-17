// ======================================== TC = 2^n ===========================================================================================

// TC is 2^n where n=size of array 'nums'. Since the resultant array sumSubset will have 2^3= 8-elements present in it. 

void findSubsets(int index, int sum, int n, vector<int> &nums, vector<int> &sumSubset){
    // Base - when we have traversed the whole array 
    if(n == index){
        sumSubset.push_back(sum);
        return;
    }
    
    // Pick the element - add it to sum and move to next element
    findSubsets(index+1, sum + nums[index], n, nums, sumSubset);
    
    // NOT Pick the element - just move to next element  
    findSubsets(index+1, sum, n, nums, sumSubset);
}

int main()
{
    vector<int> nums {3, 1, 2};
    int n = nums.size();
    
    vector<int> sumSubset;
    int sum = 0, index = 0;
    
    findSubsets(index, sum, n, nums, sumSubset);
    
    for(auto it : sumSubset){
        cout<<it<<" ";
    }

    return 0;
}
