## BRUTE : TC = O(n^2)

- Calculate the maximum possible distance between 2 cows
- Now, try whether you can fit all the cows into given stalls by maintaining a distance of '1' between them. 
- Then increase the distnace by 1 i.e d=2 and again check for above condition and keep on doing so until you are not able to fit all the cows in stalls.

```cpp
bool isCompatible(vector<int> &stalls, int d, int cows){
    int n = stalls.size();
    // Keep the 1st cow in 0th stall
    int stall = stalls[0];
    // Since we already kept a cow in 0th stall, reduce the no. of cows
    cows--;
    
    for(int i = 1; i < n; i++){
        // Check whether we can keep the cows within given distance 'd' by subtracting the current stall from previous stall
        if(stalls[i] - stall >= d){
            // As we kept a cow in current stall
            cows--;
            // If no. of cows becomes 0, we successfully assigned all cows in the stalls 
            if(!cows) return true;
            
            // Update the prev stall
            stall = stalls[i];
        }
    }
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    // Calculate the maximum distance possoble betn 2 cows i.e 'last stall - 0th stall'
    int maxDist = stalls[n-1] - stalls[0];
    // Stores the maximum distance possible
    int ans = INT_MIN;
    
    // We will try increasing the distance by 1, then 2 until we are not able to fit all the cows in stall
    for(int d = 1; d <= maxDist; d++){
        bool possible = isCompatible(stalls, d, k);
        if(possible){
            ans = max(ans, d);
        }
    }
    
    return ans;
}
```

## OPTIMAL - TC = O(n x logm)

- TC = For binary search in a space of M, O(log(M))  and for each search, we iterate over max N stalls to check - O(N)
- Calculate the max distance possible betn 2 cows i.e 'high' for binary search
- Using binary search, find the 'mid' which will be our 'distance' between cows for current iteration and check whether you can place all the cows.
- If you can place all the cows using current distance, try increasing it as we have to find max distance and do vice versa if not.

```cpp
bool canPlaceCows(vector<int> &stalls, int d, int cows){
    int n = stalls.size();
    // Keep the 1st cow in 0th stall
    int lastPlacedCow = stalls[0];
    // Since we already kept a cow in 0th stall, start counting from 1
    int countCows = 1;
    
    for(int i = 1; i < n; i++){
        // Check whether we can keep the cows within given distance 'd' by subtracting the current stall from previous stall
        if(stalls[i] - lastPlacedCow >= d){
            // As we kept a cow in current stall
            countCows++;
            
            // Update the lastPlacedCow
            lastPlacedCow = stalls[i];
        }
    }
    
    // If we placed all or even more cows, return true
    if(countCows >= cows) return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    int low = 1;
    // maximum distance possible if there are only 2 cows i.e 'last stall - 0th stall'
    int high = stalls[n-1] - stalls[0];
    
    while(low <= high){
        // 'mid' corresponds to 'distance' to be kept betn cows for current iteration
        int mid = (low+high)/2;
        
        if(canPlaceCows(stalls, mid, k)){
            // As we have to find max distance possible, so try increasing the distance
            low = mid+1;
        }
        // If we cant place all the cows, then try reducing the distance
        else{
            high = mid-1;
        }
    }
    
    return high;
}
```
