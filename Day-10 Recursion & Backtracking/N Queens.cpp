// BRUTE ===================== TC = O(n^2) ================================================================================================================================

// TC = O(n^2) -> bcoz we are running 'isSafe' func containing 3 while loops inside 'solve' func for loop everytime

/*

N-QUEENS RULES:

1. Every row must have 1 queen.
2. Every column must have 1 queen.
3. None of the queens should attack each other
*/

// Since we are moving from left to right in the board, we have to only check whether Queen is present at upper diagonal, 
// down/lower diagonal and left row of the current given position as these are the only places where a Queen may have been placed previously
bool isSafe(int row, int col, vector<string> board, int n){
    int dupRow = row;
    int dupCol = col;
    
    // Check for upper diagonal -----------------------------
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        
        // Move to previous diagonal position of the current one 
        row--;
        col--;
    }
    
    // Check for left row ----------------------------------- 
    row = dupRow;
    col = dupCol;
    
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        
        // Here the column is changing but the row is same
        col--;
    }
    
    // Check for down diagonal --------------------------------
    row = dupRow;
    col = dupCol;
    
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        
        row++;
        col--;
    }
    
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    // Base - when you reach at he last column of board 
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            // Place the Queen at the position - board[row][col] in the board
            board[row][col] = 'Q';
            // Since we can place only 1 queen , in 1 column so call recursion on the next column
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n = 4; // No. of queens 
    
    // Store all the valid chessboards in string format
    vector<vector<string>> ans;
    
    // a vector to store strings of size 'n'
    vector<string> board(n);
    
    // 's' is a string of size 'n' with all its indexes assigned to '.' -> n=4, so s = '....'
    string s(n, '.');
    
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    
    solve(0, board, ans, n);

    cout<<ans.size();
    
    return 0;
}

// OPTIMAL  =============================================== HASHING =========================================================================================

/*
For a diagonal (from right to left) :  
=> For lower Diagonal:
   addition of any Row no of diagonal + addition of any column no. of diagonal = is same i.e [Row + col]
- Thus we can track whether any 'Queen' was place before in the lowerDiagonal before instead of looping 

=> For upper Diagonal:
   Formula is : n-1 + (col - row)
*/

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    
    // Base - when you reach at he last column of board 
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col - row] == 0){
            // MArk the Queen 
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1 + col - row] = 1;
            
            solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            
            // Unmark the Queen for backtracking purpose
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1 + col - row] = 0;
        }
    }
}

int main()
{
    int n = 4; // No. of queens 
    
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    
    vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
    
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

    cout<<ans.size();
    
    return 0;
}
