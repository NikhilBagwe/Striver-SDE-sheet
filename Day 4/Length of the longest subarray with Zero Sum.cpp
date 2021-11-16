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

// OPTIMAL =================================== TC = O(nlogn)  SC = O(n) ===================================================================================================

// TC -> n = for traversing array, logn = for hashmap

int main()
{
    vector<int> nums {6, -2, 2, -8, 1, 7, 4, -10};
    int n = nums.size();
    
    int maxLen = 0;
    int curSum = 0;
    
    // Hashmap is storing the 'prefix sum' and the 'index' until the prefix sum is calculated
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++){
        curSum += nums[i];
        
        // It means that the addition of all the elements till current index 'i' gives us '0' so update maxLen
        if(curSum == 0){
            maxLen = i+1;
        }
        
        else{
            // If the curSum is pre-calculated and stored in Hashmap
            if(m.find(curSum) != m.end()){
                // Store the length of the current subarray
                /*
                eg: [1, -1, 3, 2, -2] 
                
                |<-----------sum=3--------------->|
                0.................................n
                |----sum=3 ---curSum|<-----0----->i
                
                From 0 to n(whole array), the addition of all elements is 3, and from 0 to curSum also sum=3, that means from i to n the sum will obviously be 0
                Thus we subtract from the current index i.e 'i' - m[curSum]
                */
                maxLen = max(maxLen, i-m[curSum]);
            }
            
            else{
                // Store in Hashmap
                m[curSum] = i;
            }
        }
    }
    
    cout<<maxLen;

    return 0;
}
