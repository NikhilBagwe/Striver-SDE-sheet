// BRUTE ================= Binary Search to find 4th element===================== TC = O(n^3 * logn) ===================================================================

int main()
{
    vector<int> nums {4,3,3,4,4,2,1,2,1,1};
    int n = nums.size(), target = 9;
    
    sort(nums.begin(), nums.end());
    
    set<vector<int>> ans;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int s=k+1, e=n-1;
                
                int target_2 = target - (nums[i] + nums[j] + nums[k]);
                vector<int> a;
                while(s < e){
                    int mid = s+(e-s)/2;
                    
                    if(nums[mid] == target_2){
                        a.push_back(nums[i]);
                        a.push_back(nums[j]);
                        a.push_back(nums[k]);
                        a.push_back(nums[mid]);
                        ans.insert(a);
                        break;
                    }
                    
                    else if(mid > target_2) e = mid - 1;
                    
                    else s = mid + 1;
                }
            }
        }
    }
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// OPTIMAl ================= TWO SUM by SKIPPING DUPLICATE ELEMENTS =================== TC = O(n^3) =====================================================================

int main()
{
    vector<int> nums {4,3,3,4,4,2,1,2,1,1};
    int n = nums.size(), target = 9;
    
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> ans;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int s = j+1, e = n-1;
            
            int target_2 = target - nums[i] - nums[j];
            
            while(s < e){
                int two_sum = nums[s] + nums[e];
                
                if(two_sum > target_2) e--;
                
                else if(two_sum < target_2) s++;
                
                else{
                    vector<int> v(4, 0);
                    v[0] = nums[i];
                    v[1] = nums[j];
                    v[2] = nums[s];
                    v[3] = nums[e];
                    ans.push_back(v);
                    
                    // Skipping duplicate elements if any
                    while(s<e && nums[s]==v[2]) s++;
                    while(s<e && nums[e]==v[3]) e--; 
                }
            }
            
            // Skipping duplicate elements if any
            while(j+1<n && nums[j+1]==nums[j]) ++j;
        }
        
        // Skipping duplicate elements if any
        while(i+1<n && nums[i+1]==nums[i]) ++i;
    }
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}
