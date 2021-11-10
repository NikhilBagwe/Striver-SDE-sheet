// BRUTE ======================================================= TC = O(n^2)  SC = O(n^2) ==============================================================================

int main()
{ 
    vector<vector<int>> mat {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
                             
    
    // Initialize a 3x3 matrix containig '0' at all places
    vector<vector<int>> rot(3, vector<int>(3, 0));
    
    int rows = mat.size(), cols = mat[0].size();
    
    // Initialized row and col pointer for rotated matrix - Logic to assign 1st row as LAST column and so on.
    int row = 0, col = cols-1;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            rot[row++][col] = mat[i][j];
        }
        // Before moving to the next row, get the row pointer back to 0th row and move to prev column 
        row = 0;
        col--;
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<rot[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// OPTIMAL ======================================================= TC = O(n^2) =======================================================================================

/*
1. Transpose of matrix
2. Reverse each row 

Intution:
- The reversal of 1st row of transposed matrix, is the 1st row of the rotated matrix gives the hint to take transpose.
  1 4 7                   
  2 5 8  <- Transpose  
  3 6 9
  
  7 4 1 
  8 5 2  <- Rotated matrix
  9 6 3 
- Since its a reversal, reverse each row of the transpoed matrix

*/

int main()
{ 
    vector<vector<int>> mat {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
                             
    
    int rows = mat.size(), cols = mat[0].size();
    
    for(int i = 0; i < rows; i++){
        // Iterate from "0 to i" to take transpose of matrix
        for(int j = 0; j < i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    // Reverse each row of the transpoed matrix
    for(int i = 0; i < rows; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
