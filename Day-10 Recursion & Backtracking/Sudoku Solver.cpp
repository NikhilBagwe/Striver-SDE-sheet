/*
Sudoku:

- It is a 9x9 board.
- Contains nine 3x3 matrix inside it

Rules:

1. The digits 1 to 9 should appear exactly once in every row.
2. The digits 1 to 9 should appear exactly once in every column.
3. The digits 1 to 9 should appear exactly once in every 3x3 matrix.

LOGIC :

1. Using recursion find the empty space in sudoku where we have to insert a number.
2. On finding the empty space, try inserting numbers from 1 to 9 in it and also at the same time keep a check whether the number is 
   present in the respective row, column and matrix.
   
*/

bool isValid(vector<vector<char>> &board, int row, int col, char c){
    // i / 3 -> indicates change in rows
    // i % 3 -> indicates change in columns
    // divided and multiplied by 3 -> since size of matrix is '3'
    
    for(int i = 0; i < 9; i++){
        // Checks the entire column 
        if(board[i][col] == c){
            return false;
        }
        
        // Checks the entire row
        if(board[row][i] == c){
            return false;
        }
        
        // Checks the 3x3 matrix
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c){
            return false;
        }
    }
    
    return true;
}

bool solve(vector<vector<char>> &board){
    // Iterate the whole matrix 
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            
            // When you find an empty space 
            if(board[i][j] == '.'){
                // Try inserting all numbers from 1 to 9 to see which fits at that empty space following all rules 
                
                for(char c = 1; c <= 9; c++){
                    // Check if the current number is already present in the row, column and matrix
                    if(isValid(board, i, j, c)){
                        // Insert the number 
                        board[i][j] = c;
                        
                        // Call the next recursion Call
                        if(solve(board) == true){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                
                return false;
            }
        }
    }
    // If we reach here means we have filled the entire sudoku correctly so return true
    return true; 
}

int main()
{
    cout<<"Hello World";

    return 0;
}
