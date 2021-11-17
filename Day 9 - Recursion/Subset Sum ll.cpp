// BRUTE ================================================ TC = 2^n + (2^n)log(2^n) ============================================================================

// Same as previous Subset sum 1 problem only instead of 'sum' pass 'temp' vector
// (2^n)log(2^n) -> To put unique subsets inot 'set' DS
 
void findSubsets(int index, vector<int> &temp, int n, vector<int> &nums, set<vector<int>> &sumSubset){
    // Base - when we have traversed the whole array 
    if(n == index){
        sumSubset.insert(temp);
        return;
    }
    
    // Pick the element - insert it into temp and move to next element
    temp.push_back(nums[index]);
    findSubsets(index+1, temp, n, nums, sumSubset);
    
    // NOT Pick the element - here remove the element that we inserted above in the 'temp'   
    temp.pop_back();
    findSubsets(index+1, temp, n, nums, sumSubset);
}

int main()
{
    vector<int> nums {1, 2, 2};
    int n = nums.size();
    
    // Store unqiue subsets only
    set<vector<int>> sumSubset;
    
    // Store the current subset temporarily at time of recursion
    vector<int> temp;
    
    int index = 0;
    
    findSubsets(index, temp, n, nums, sumSubset);
    
    for(auto it : sumSubset){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// BRUTE ================================================ TC = 2^n * n , SC = O(2^n) * O(k) ============================================================================

// TC = 2^n * n -> 2^n for recurssive call and 'n' as every time we are adding a 'ds' to 'ans' which can be of maximum size 'n'
// SC = O(2^n) * O(k) -> At worst we will store 2^n subsets into 'ans' and their average lenght might be O(k)

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);
        
        for(int i = ind;i<nums.size();i++) {
            // We have to pickup the element only once so we perform this check
            if(i!=ind && nums[i] == nums[i-1]) continue;
            
            ds.push_back(nums[i]); 
            findSubsets(i+1, nums, ds, ans); 
            
            ds.pop_back(); 
        }
    }
int main()
{
    vector<int> nums {1, 2, 2, 2, 3, 3};
    int n = nums.size();
    
    // Store unqiue subsets only
    vector<vector<int>> ans;
    
    // Store the current subset temporarily at time of recursion
    vector<int> ds;
    
    findSubsets(0, nums, ds, ans);
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}
