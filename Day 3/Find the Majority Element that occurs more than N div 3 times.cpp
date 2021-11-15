// BRUTE ============================================== TC = O(n) SC = O(n) ====================================================================================

int main()
{
    vector<int> nums {1, 1, 1, 2, 2, 1, 2, 3};
    int n = nums.size();
    
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++){
        m[nums[i]]++;
        
        if(m[nums[i]] > n/3){
             cout<<nums[i]<<" ";
             m[nums[i]] -= 3;
        }
    }
    
    return 0;
}

// OPTIMAL ==================== Extended Moore's voting algo =================== TC = O(n) + O(n) ============================================================================

int main()
{
    vector<int> nums {1, 1, 1, 2, 2, 1, 2, 3};
    int n = nums.size();
    
    int can1 = -1, can2 = -1;
    int count1 = 0 , count2 = 0;
    
    for(int i=0; i<n; i++){
        if(nums[i] == can1) count1++;
        
        else if(nums[i] == can2) count2++;
        
        else if(count1 == 0){
            can1 = nums[i];
            count1 = 1;
        }
        
        else if(count2 == 0){
            can2 = nums[i];
            count2 = 1;
        }
        
        else{
            count1--;
            count2--;
        }
    }
    
    int f1=0, f2=0;
    
    for(int i=0; i<n; i++){
        if(nums[i] == can1) f1++;
    }
    for(int i=0; i<n; i++){
        if(nums[i] == can2) f2++;
    }
    
    if(f1 > n/3) cout<<can1<<" ";
    if(f2 > n/3) cout<<can2;
    
    return 0;
}
