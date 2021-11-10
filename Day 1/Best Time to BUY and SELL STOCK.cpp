// BRUTE ===================================================================== O(n^2) ============================================================================

int main()
{
    vector<int> a {7, 1, 5, 3, 6, 4};
    int n = a.size();
    
    int maxProfit = 0;
    
    for(int i=0; i<n; i++){
        int curProfit = 0;
      
        for(int j = i+1; j<n; j++){
          
            if(a[i] < a[j]) {
                curProfit = a[j] - a[i];
                maxProfit = max(curProfit, maxProfit);
            }
          
        }
    }
    
    cout<<maxProfit;
    
    return 0;
}

// OPTIMAL ===================================================================== O(n) ============================================================================

/*
1. Keep the track of minimum value i.e minPrice, on the leftside. 
2. Assign 'minPrice = 1e9' and 'maxProfit = 0'
*/

int main()
{
    vector<int> prices {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    
    int maxProfit = 0;
    int minPrice = INT_MAX; // or 1e9
    
    for(int i=0; i<n; i++){
        // update minPrice on every iteration
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i]-minPrice);
    }
    
    cout<<maxProfit;
    
    return 0;
}
