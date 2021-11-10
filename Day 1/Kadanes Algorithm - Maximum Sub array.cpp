// BRUTE ======================================================== O(n^3) ======================================================================================

int main()
{
    int maxSum = 0;
    vector<int> a {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = a.size();
    
    for(int i = 0; i<n; i++){
      
        for(int j = i; j<n; j++){
            int curSum = 0;
          
            for(int k = i; k<j; k++){
                curSum += a[k];
            }
          
            maxSum = max(curSum, maxSum);
        }
    }
    
    cout<<maxSum;
    
    return 0;
}

// OPTIMAL ====================================================== Kadanes Algorithm ============ O(n) ========================================================

// condition -> the max sub array should have atleast 1 element present in it

// Kadanes algo Intuition - We carry a sum as long it gives us a POSITIVE sum.

// Also works for all negative number array

int main()
{
    vector<int> nums {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = nums.size();
    
    int maxSum = INT_MIN; // or maxSum = nums[0] -> assign the 1st element 
    int sum = 0;
    
    for(auto it : nums){
        sum += it;
        maxSum = max(sum, maxSum);
        
        // If at any point 'sum' becomes negative, assign it back to '0' (as per the intution)
        if(sum < 0){
            sum = 0;
        }
    }
    
    cout<<maxSum;
    
    return 0;
}
