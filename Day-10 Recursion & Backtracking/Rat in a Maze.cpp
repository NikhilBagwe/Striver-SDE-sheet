// OPTIMAL - NOT A CLEAN CODE ========================== TC = 4 ^ (n*m) , sc = O(n*m) ==========================================================================

/*
TC = 4 ^ (n*m) -> since we are trying four different ways for every cell
sc = O(n*m) -> Size of matrix which is the Depth of the recursion tree i.e the auxiliary space

LOGIC: 

1. We start to traverse the maze from the starting point i.e (0, 0) and then for each cell we check whether we can
   move Upwards, downwards, Left and Right.
2. While traversing we keep a track of how many cells we visited using 'vis' array as we can visit each cell only once.
*/

void findPaths(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string path, vector<vector<int>> &vis){
    // Base - When you reach the end-point 
    if(i == n-1 && j == n-1){
        ans.push_back(path);
        return;
    }
    
    // Move downwards - So increment 'i' by 1 and check whether it is not going outbound also check that cell is not visited and 
    // '1' is present in that cell of the maze as '0' mean blocked
    if(i+1 < n && !vis[i+1][j] && a[i+1][j] == 1){
        vis[i][j] = 1;
        findPaths(i+1, j, a, n, ans, path + 'D', vis);
        vis[i][j] = 0;
    }
    
    // Left
    if(j-1 >= 0 && !vis[i][j-1] && a[i][j-1] == 1){
        vis[i][j] = 1;
        findPaths(i, j-1, a, n, ans, path + 'L', vis);
        vis[i][j] = 0;
    }
    
    // Right
    if(j+1 < n && !vis[i][j+1] && a[i][j+1] == 1){
        vis[i][j] = 1;
        findPaths(i, j+1, a, n, ans, path + 'R', vis);
        vis[i][j] = 0;
    }
    
    // Upwards 
    if(i-1 >= 0 && !vis[i-1][j] && a[i-1][j] == 1){
        vis[i][j] = 1;
        findPaths(i-1, j, a, n, ans, path + 'U', vis);
        vis[i][j] = 0;
    }
}

int main()
{
    vector<vector<int>> maze {{1,0,0,0}, 
                              {1,1,0,0},            
                              {1,1,0,0}, 
                              {0,1,1,1}};
    
    int n = maze.size();
    // vector string to store paths 
    vector<string> ans;
    
    // Visited array 
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    // If the starting point is valid i.e '1' than only we can start traversing the maze
    if(maze[0][0] == 1){
        findPaths(0, 0, maze, n, ans, "", vis);
    }
    
    for(auto it : ans){
        for(auto c : it){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}
