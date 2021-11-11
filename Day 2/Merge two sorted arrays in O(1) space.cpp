// BRUTE ======================================= TC = O(nlogn) + O(n), SC = O(n1+n2) =============================================================================
/*
1. Put all the elements from both arrays into a temp array
2. Then sort the temp array
3. Then put the sorted elemnents from temp array back into the 2 arrays
*/

int main()
{
    vector<int> arr1 {1, 4, 7, 8, 10};
    int n1 = arr1.size();
    vector<int> arr2 {2, 3, 9};
    int n2 = arr2.size();
    
    vector<int> temp(n1+n2, 0);
    
    // Put all the elements from arr1 and arr2 into 'temp'
    for(int i=0; i<n1; i++){
        temp[i] = arr1[i];
    }
    for(int i=n1; i<n1+n2; i++){
        temp[i] = arr2[i-n1];
    }
    
    // Sort the 'temp' vector
    sort(temp.begin(), temp.end());
    
    // After sorting 'temp', put its all elements back into respective arr1 and arr2
    for(int i=0; i<n1; i++){
        arr1[i] = temp[i];
    }
    for(int i=0; i<n2; i++){
        arr2[i] = temp[i+n1];
    }
    
    // Print the sorted arrays
    for(auto it: arr1){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: arr2){
        cout<<it<<" ";
    }

    return 0;
}
