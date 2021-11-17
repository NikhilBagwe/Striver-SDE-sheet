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
