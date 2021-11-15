// BRUTE ================================================== Hash map =============================================================================

int main()
{
    vector<int> nums {4,4,2,4,3,4,4,3,2,4};
    int n = nums.size();
  
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++){
        m[nums[i]]++;
        
        if(m[nums[i]] > n/2){
            cout<<nums[i];
            break;
        }
    }

    return 0;
}

// OPTIMAL ============================ Moore's voting algo =================================================================================

int main()
{
    vector<int> nums {4,4,2,4,3,4,4,3,2,4};
    int n = nums.size();
    
    int candidate = nums[0];
    int votes = 1;
    
    for(int i=1; i<n; i++){
        if(nums[i] == candidate) votes++;
        else votes--;
        
        if(votes == 0){
            candidate = nums[i];
            votes = 1;
        }
    }
    
    cout<<candidate;

    return 0;
}
