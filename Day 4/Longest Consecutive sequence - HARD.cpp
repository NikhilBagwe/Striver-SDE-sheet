// BRUTE ====================================== TC= O(nlogn) ===========================================================================================================

int main()
{
    vector<int> nums {102, 100, 1, 103, 3, 2, 101};
    int n = nums.size();
    
    // Sort the array 
    sort(nums.begin(), nums.end());
    
    // Store the maximum lenght of subsequence
    int maxLength = 0;
    // Counts the length of current subsequence
    int counter = 0;
    
    for(int i=0; i<n; i++){
        // Check whether the "current number + 1" is equal to "next number"
        if(nums[i]+1 == nums[i+1]) counter++;
        
        // If not equal then
        else if(nums[i]+1 != nums[i+1]){
            // Count the current number into the lenght of current subsequence
            counter++;
            // Store the max length 
            maxLength = max(maxLength, counter);
            // Reset the counter back to '0' to count for further subsequences if any
            counter = 0;
        }
    }
    
    cout<<maxLength;

    return 0;
}

// OPTIMAL ==================================================== TC= O(nlogn) , SC = O(n) ================================================================================

/*
LOGIC:

1. Actually the soln looks like an O(n^2) solution, but actually its O(3n).
2. Here we 1st put all elements into hashSet so -> O(n)
3. Then we again iterate on the array and check whether a number less than the current number exists or not and doing so
   we reach to the 1st element of the subsequence. -> O(n)
4. After reaching the 1st element, we start counting the length of subsequence using while loop ->O(n)

Thus TC = O(n)+O(n)+O(n) = O(3n)
*/

int main()
{
    vector<int> nums {102, 100, 1, 103, 3, 2, 101};
    int n = nums.size();
    
    set<int> hashSet;
    
    // Store all elements into hashSet
    for(auto num : nums){
        hashSet.insert(num);
    }
    
    int maxLength = 0;
    
    for(auto num : nums){
        // Check whether a number less than current number exists or not. If it dosent than continue
        if(!hashSet.count(num-1)){
            int currentNum = num;
            int currentLenght = 1;
            
            // Check whther the next number after currentNum exists or not.
            // eg: currentNum=100, check whether 101 exists
            while(hashSet.count(currentNum+1)){
                currentNum += 1;
                currentLenght += 1;
            }
            
            maxLength = max(maxLength, currentLenght);
        }
    }
    
    cout<<maxLength;

    return 0;
}
