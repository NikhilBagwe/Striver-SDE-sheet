## OPTIMAL - TC = O(n*logn) , SC = O(1)

- Sort both the arrival and departure time arrays.
- Now start applying 2 pointer approach from 2nd arrived train and 1st departed train as 1st arrived train is already consumed one platform

```cpp
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	// Initially the 1st train will take up one platform
    	int plat_needed = 1;
    	// Stores the maximum no. of platforms required
    	int result = 1;
    	
    	// Apply 2 pointer approach and start from the 2nd ARRIVED train and 1st Departed train
    	int i = 1, j = 0;
    	
    	while(i < n && j < n){
    	    // If the arr[i] train arrived before dep[j] train gets departed, than we need one more platform
    	    if(arr[i] <= dep[j]){
    	        plat_needed++;
    	        i++;
    	    }
    	    
    	    // If the dep[j] train departed before arr[i] train came, reduce the platform count as one paltform is already vacant
    	    else if(arr[i] > dep[j]){
    	        plat_needed--;
    	        j++;
    	    }
    	    
    	    // Update the max no. of platforms needed throughout
    	    result = max(plat_needed, result);
    	}
    	
    	return plat_needed;
    }
};

```
