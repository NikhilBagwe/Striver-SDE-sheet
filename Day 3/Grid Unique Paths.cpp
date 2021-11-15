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
