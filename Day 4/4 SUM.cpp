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
