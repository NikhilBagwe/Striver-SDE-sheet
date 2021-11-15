// BRUTE ================================ RECURSION ====== TC and SC will be exponentional as you will try out all the paths and use the stack space =======================

int countPaths(int i, int j, int m, int n){
    // Base condition - When we reach the end point
    if(i == m-1 && j == n-1){
        return 1;
    }
    
    // When 'i' and 'j' goes out of bound no path can be formed
    if(i >= m || j >= n){
        return 0;
    }
    
    else return countPaths(i+1, j, m, n) + countPaths(i, j+1, m, n);
}

int main()
{
    int m=2, n=3; // rows x columns
    // As per the question, the start point is (0, 0) and end point is (1, 2)
    
    int i=0, j=0;
    
    int numberOfPaths = countPaths(i, j, m, n);
    
    cout<<numberOfPaths;
    
    return 0;
}

// OPTIMAL ================= DP APPROACH ====== TC = O(n*m) SC = O(n*m) ========================================================================================

int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
    if(i == m-1 && j == n-1){
        return 1;
    }
    
    if(i >= m || j >= n){
        return 0;
    }
    
    // Return the pre-computed value
    if(dp[i][j] != -1) return dp[i][j];
    
    // At time of returning store the value in dp matrix
    else return dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
}

int main()
{
    int m=2, n=3; // rows x columns
    
    int i=0, j=0;
    // Init a dp matrix of m*n filled with '-1'
    vector<vector<int>> dp(m, vector<int> (n, -1));
    
    int numberOfPaths = countPaths(i, j, m, n, dp);
    
    cout<<numberOfPaths;
    
    return 0;
}

// BETTER ============ Combinatrics ==============================TC = O(n-1) or O(m-1) ====================================================================================

/*
Combinatrics approach :

eg: int m=2, n=3; // rows x columns
    // As per the question, the start point is (0, 0) and end point is (1, 2)
    
1. Visually find all the paths to reach from start to end point.
2. The paths are RRD, RDR, DRR
3. We make the following observations from paths:
   - We need to take 3 steps to reach end point
   - The no. of times we need to take right direction is (n-1) and down direction is (m-1) always.
4. Thus, the total no. of directions needed to be taken => (n-1) + (m-1) = n + m -2
5. The equations are:
   - (n + m -2) C (m-1) 
            OR 
   - (n + m -2) C (n-1)
   
Formula of nCr:
eg: 10 C 3 = (8 x 9 x 10) / (1 x 2 x 3)

- last 3 digits from 10 / digits from 3 to 1
*/
