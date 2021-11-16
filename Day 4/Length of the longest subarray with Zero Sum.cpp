// BRUTE ======================================================================================================================================

int main()
{
    vector<int> nums {6, -2, 2, -8, 1, 7, 4, -10};
    int n = nums.size();
    
    // There will be atleast 1 element in array so that's why maxLen=1
    int maxLen = 1;
    
    for(int i=0; i<n; i++){
        int curSum = nums[i];
        int curLen = 1;
        
        for(int j=i+1; j<n; j++){
            curSum += nums[j];
            curLen += 1;
            
            if(curSum == 0){
                maxLen = max(maxLen, curLen);
            }
        }
    }
    
    cout<<maxLen;

    return 0;
}
