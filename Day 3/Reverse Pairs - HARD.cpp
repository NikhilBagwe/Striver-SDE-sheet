// BRUTE =======================================================================================================================================================

int main()
{
    vector<int> a {1, 3, 2, 3, 1};
    int n = a.size();
    int count = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > 2*a[j]) count++;
        }
    }
    
    cout<<count;

    return 0;
}

// OPTIMAL ============== Modified Merge Sort ============= TC = O(nlogn) + O(n) + O(n) ============================================================================

int merge(vector<int> &a, int low, int mid, int high){
    // Stores total no. of reverse pairs
    int count = 0;
    // point 'j' to start of right subarray
    int j = mid+1;
    
    // Iterate 'i' on the left subarray from 'low' to 'mid'
    for(int i = low; i <= mid; i++){
        // Now keep moving 'j' until the right subarray is exhausted and check for the condition also
        while(j <= high && a[i] > 2*a[j]){
            j++;
        }
        // Count the no. of elemnets on the left that will contribute to no. of pairs of the 'ith' index elemnet as of now
        count += (j-(mid+1));
    }
    
    // Normal MERGE function ---------------------------------------------
    vector<int> temp;
    int left = low, right = mid+1;
    
    while(low <= mid && right <=high){
        if(a[left] <= a[right]){
            temp.push_back(a[left++]);
        }
        
        else{
            temp.push_back(a[right++]);
        }
    }
    
    while(left <= mid){
        temp.push_back(a[left++]);
    }
    
    while(right <= high){
        temp.push_back(a[right++]);
    }
    
    for(int i=low; i<=high; i++){
        a[i] = temp[i-low];
    }
    
    return count;
}

int mergeSort(vector<int> &a, int low, int high){
    if(low >= high) return 0;
    
    int mid = (low+high)/2;
    int inv = mergeSort(a, low, mid);
    inv += mergeSort(a, mid+1, high);
    inv += merge(a, low, mid, high);
    
    return inv;
}

int main()
{
    //vector<int> a {1, 3, 2, 3, 1};
    vector<int> a {40, 25, 19, 12, 9, 6, 2};
    int n = a.size();
    
    int ans = mergeSort(a, 0, n-1);
    
    cout<<ans;

    return 0;
}
