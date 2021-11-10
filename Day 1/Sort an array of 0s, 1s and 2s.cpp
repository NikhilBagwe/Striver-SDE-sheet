// BRUTE - Sort the array ========================= O(nlogn) ==============================



// OPTIMAL ========================================================= O(n) + O(n) = O(2n) ===========================================================================

int main()
{
    int a[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = 12;
    
    int c0=0, c1=0, c2=0;
    
    for(int i=0; i<n; i++){
        if(a[i] == 0) c0++;
        
        else if(a[i] == 1) c1++;
        
        else c2++;
    }
    
    int k = 0;
    for(int i = 0; i < c0; i++) a[k++] = 0;
    for(int i = 0; i < c1; i++) a[k++] = 1;
    for(int i = 0; i < c2; i++) a[k++] = 2;

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

// BETTER ========================================= O(n) ========== Dutch National flag algorithm ===========================================================

/*
Initial assumption is :

- everything from a[0]....a[low-1] = 0
- everything from a[low]....a[mid-1] = 1
- everything from a[high+1]....a[n-1] = 2

*/

int main()
{
    vector<int> a {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = a.size()-1;
    
    int low = 0, mid = 0, high = n-1;
    
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[low++], a[mid++]);
        }
        
        else if(a[mid] == 1){
            mid++;
        }
        
        else{
            swap(a[mid], a[high--]);
        }
    }
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
