// BRUTE =============================================== O(nlogn) =============================================================================================

int main()
{
    vector<int> nums {1, 3, 2, 10, 5, 2, 4};
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<n; i++){
        // Check if the current and the next no. are same or not, as duplicate no. will be present next to each other after sorting
        if(nums[i] == nums[i+1]){
            cout<<"Duplicate number : "<<nums[i];
            break;
        }
    }

    return 0;
}

// OPTIMAL =============================================== HASHING === TC = O(n) , SC = O(n) =================================================================================

int main()
{
    vector<int> nums {1, 3, 2, 10, 5, 2, 4};
    int n = nums.size();
    
    vector<int> hashVector(n, 0);
    
    for(int i=0; i<n; i++){
        // If we have already marked that place as 1, means the current number is Duplicate
        if(hashVector[nums[i]] == 1){
            cout<<"Duplicate number : "<<nums[i];
            break;
        }
        
        else{
            hashVector[nums[i]]++;
        }
    }
    
    return 0;
}
