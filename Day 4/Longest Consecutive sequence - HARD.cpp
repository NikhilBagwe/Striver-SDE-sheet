// BRUTE ======================================================================================================================================

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
