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
