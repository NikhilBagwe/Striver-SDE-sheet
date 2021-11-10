// link = https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

// PRINT THE WHOLE PASCAL TRIANGLE =======================================================================================================================

int main()
{
    int rows = 5; // no. of pascal triangle rows
    vector<vector<int>> m(rows);
    
    for(int i = 0; i<rows; i++){
        // increase the size of array 
        m[i].resize(i+1);
        // Initialize the first and last value to '1'
        m[i][0] = m[i][i] = 1;
        
        // iterate from index 1 to second-last index to fill up the remaining middle positions
        for(int j=1; j<i; j++){
            m[i][j] = m[i-1][j-1] + m[i-1][j];
        }
    }
    
    for(auto it : m){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// PRINT A SPECIFIC ROW  ==========================================================================================================================================

// n -> no. of rows in the pascal triangle
// row -> specific row no. to be printed
void printPascalRow(int n, int row){
    vector<vector<int>> r(n);
    
    for(int i = 0; i<n; i++){
        r[i].resize(i+1);
        r[i][0] = r[i][i] = 1;
        
        for(int j = 1; j<i; j++){
            r[i][j] = r[i-1][j-1] + r[i-1][j]; 
        }
        
        // print the specific row and then break
        if(i == row-1){
            for(int k=0; k<=i; k++){
                cout<<r[i][k]<<" ";
            }
            break;
        }
    }
}

int main()
{
    int n = 5;
    
    printPascalRow(n, 4);
    
    return 0;
}
