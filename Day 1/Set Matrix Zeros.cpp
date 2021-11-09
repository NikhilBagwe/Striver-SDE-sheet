// BRUTE --------------------------------------------------------- TC = O(n^3) ----------------------------------------------------------------------------

int main()
{
    vector<vector<int>> m  {{0, 28, 0},
                           {22, 41, 7},
                           {27,  8, 87}};
    
    // Traverse the matrix and wherever '0' is present, change its whole row and column to '-1'
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(m[i][j] == 0){
                
                for(int r=0; r<3; r++){
                    if(m[i][r] != 0){
                        m[i][r] = -1;
                    }
                }
                
                for(int c=0; c<3; c++){
                    if(m[c][j] != 0){
                        m[c][j] = -1;
                    }
                }
            }
        }
    }
    
    // Traverse the matrix and wherever '-1' is present, replace it with '0'
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(m[i][j] == -1){
                m[i][j] = 0;
            }
        }
    }
    
    // Display the final matrix
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<<m[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}

// OPTIMAL --------------------------------------------------------- TC = O(n^2) ----------------------------------------------------------------------------

/*
1. Here we are considering the topmost ROW and leftmost COLUMN as two dummy arrays.
2. wherever we find '0' in the matrix, we will set the leftmost and the topmost position to '0'
3. We have to keep a track of whether the 0 was inserted into the 0th column by the dummy array or was present in the 
   question itself by using 'col0'
*/

int main()
{
    vector<vector<int>> m  {{0, 28, 1},
                           {22, 0, 7},
                           {27,  8, 87}};
    int rows = m.size(), columns = m[0].size();
    int col0 = 1;
    
    for(int i = 0; i<rows; i++){
        // Check whether the value present at the 0th column of any row is '0' since we are using it as dummy array
        // col0 is set to 0     -> means there is really a '0' present in column 0 
        // col0 is not set to 0 -> means any value in the col0 maybe set by the dummy array to '0', meaning '0' was not originally present in col0
        if(m[i][0] == 0) col0 = 0;
        
        // Traverse for the rest of the columns from '1'
        for(int j = 1; j<columns; j++){
            if(m[i][j] == 0){
                // Set the leftmost and the topmost position to '0'
                m[i][0] = m[0][j] = 0;
            }
        }
    }
    
    // Linearly traverse the matrix from backwards
    for(int i = rows-1; i>=0; i--){
        for(int j = columns-1; j>=0; j--){
            // Check whether the value present in the dummy array is '0' for the given index
            if(m[i][0] == 0 || m[0][j] == 0){
                m[i][j] = 0;
            }
        }
        // Check whether a 0 is present in the 0th column naturally, or was set by the dummy array 
        if(col0 == 0) m[i][0] =0;
    }
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<<m[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
