// OPTIMAL ============================================================= TC = O(n+logm) =============================================================================

// Apply binary search on each row 

int main()
{
    int r = 3, c = 3;
    vector<vector<int>> matrix {{1, 3, 5, 7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}};
    
    int flag = 0, target = 16;
    
    for(int i=0; i<r; i++){
        int s=0, e=c-1, mid=0;
        
        while(s <= e){
            mid = s+(e-s)/2;
            
            if(matrix[i][mid] == target){
                cout<<"Element found at "<<i<<" "<<mid;
                flag=1;
                break;
            }
            
            else if(matrix[i][mid] > target) e = mid - 1;
            
            else s = mid + 1;
        }
    }
    
    if(flag == 0) cout<<"Element absent";

    return 0;
}

// BETTER ============================================================= TC = O(logn) =============================================================================

int main()
{
    
    vector<vector<int>> matrix {{1, 3, 5, 7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}};
    
    int r = matrix.size(), c = matrix[0].size();
    
    int flag = 0, target = 50;
    
    // Applying an imaginary binary search on the whole matrix as we consider it as a single sorted array 
    // ROW = mid/c 
    // COLUMN = mid % c
    int i=0, j=(r*c)-1;
    
    while(i <= j){
        int mid = i+(j-i)/2;
        
        if(matrix[mid/c][mid%c] == target){
            cout<<"Element found at : "<<mid/c<<" "<<mid%c;
            flag = 1;
            break;
        }
        
        else if(matrix[mid/c][mid%c] > target) j = mid -1;
        
        else i = mid + 1;
    }
    
    if(flag == 0) cout<<"Element absent";

    return 0;
}
