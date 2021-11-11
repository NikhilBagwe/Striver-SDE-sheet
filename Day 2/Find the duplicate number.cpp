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

// BETTER ================ Floyd's Tortoise and Hare (Cycle Detection) ========================= TC = O(n) =======================================================

/*
1. Init 2 pointers - fast and slow
2. Move the 'slow' ptr at speed of '1' and fast by '2' until they collide.
3. When 1st collision takes place i.e slow == fast, come out of loop
4. Take fast ptr back to the start of array 
5. Move both the pointers by 1 to find the duplicate no.
*/

int main()
{
    vector<int> nums {2, 5, 8, 6, 8, 3, 8, 9, 7, 1};
    int n = nums.size();
     
    int slow = nums[0];
    int fast = nums[0];
    
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    
    fast = nums[0];
    
//     slow = nums[slow];
//     fast = nums[fast];
    
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    
    cout<<slow;
    
    return 0;
}
