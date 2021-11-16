// BRUTE ========================================================== O(n^2) ======================================================================================

int main()
{
    vector<int> nums {3,2,4,6};
    int n = nums.size(), target = 9;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
                cout<<"Element present at index : "<<"["<<i<<" ,"<<j<<"]";
                return 0;
            }
        }
    }
    
    cout<<"Element absent";

    return 0;
}

// OPTIMAL ========================================================== O(nlogn) ======================================================================================

int main()
{
    vector<int> nums {3,2,4,6};
    int n = nums.size(), target = 9;
    
    sort(nums.begin(), nums.end());
    
    int s=0, e=n-1;
    
    while(s < e){
        if(nums[s] + nums[e] == target){
            cout<<"Element present at index in sorted array : "<<"["<<s<<" ,"<<e<<"]";
            return 0;
        }
        
        else if(nums[s] + nums[e] > target) e--;
        
        else s++;
    }
    
    cout<<"Element absent";

    return 0;
}

// BETTER ==================== Hashmap =============================== TC = O(n), SC = O(n) =================================================================================

int main()
{
    vector<int> nums {3,2,4,6};
    int n = nums.size(), target = 7;
    
    // Store the indexes of the elements adding up to the target
    vector<int> ans;
    // Hashmap
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++){
        // m.end() => points to the place after the last element in map 
        if(m.find(target - nums[i]) != m.end()){
           ans.push_back(m[target - nums[i]]);
           ans.push_back(i);
           break;
        }
        
        // Assigh the current index to the current element
        m[nums[i]] = i;
    }
    
    for(auto it : ans){
        cout<<it<<" ";
    }

    return 0;
}
