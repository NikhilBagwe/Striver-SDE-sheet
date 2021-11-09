
// Using inbuilt function ============================================================================================

int main()
{
    int a[] = {1,3,2};
    
    next_permutation(a, a+3);
    
    cout<<a[0]<<" "<<a[1]<<" "<<a[2];
    
    return 0;
}

// OPTIMAL ==================================================== O(n) ==================================================================

void nextPermutation(vector<int> &nums){
    int n = nums.size(), k, l;
    
    // Find the breakdown point and iterate from the 2nd last index 
    for(k = n-2; k>=0; k--){
        if(nums[k] < nums[k+1]){
            break;
        }
    }
    
    // Array is in decreasing order eg. 4321 so just reverse it
    if(k < 0){
        reverse(nums.begin(), nums.end());
    }
    else{
        // Step 2
        for(l = n-1; l > k; l--){
            if(nums[l] > nums[k]){
                break;
            }
        }
        // Step 3
        swap(nums[k], nums[l]);
        // Step 4
        reverse(nums.begin()+k+1, nums.end());
    }
}

int main()
{
    vector<int> nums {1,3,5,4,2};
    nextPermutation(nums);
    
    for(auto it : nums){
        cout<<it<<" ";
    }

    return 0;
}
