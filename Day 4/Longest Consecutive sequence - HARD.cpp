// BRUTE ======================================================================================================================================

int main()
{
    vector<int> nums {102, 4, 100, 1, 101, 3, 103, 104, 105, 106};
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    int maxLength = 0;
    int counter = 0;
    
    for(int i=0; i<n; i++){
        
        if(nums[i]+1 == nums[i+1]) counter++;
        
        else if(nums[i]+1 != nums[i+1]){
            counter++;
            maxLength = max(maxLength, counter);
            counter = 1;
        }
        cout<<counter<<" ";
    }
    
    cout<<maxLength;

    return 0;
}
