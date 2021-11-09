// link = https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

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
