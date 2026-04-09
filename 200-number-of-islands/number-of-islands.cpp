class Solution {
public: 

    int dr[4] = {0,0,-1,1};
    int dc[4] = {-1,1,0,0};
    
    void dfs(vector<vector<char>>&grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() 
   || grid[r][c] == '0' || grid[r][c] == '2') return;

        else if(grid[r][c] == '1'){
            grid[r][c] = '2';
            for(int i = 0; i < 4; i++){
                int rr = dr[i] + r;
                int cc = dc[i] + c;
                dfs(grid, rr, cc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        // vector<pair<int,int>>colors;
        int m = grid.size();
        int n = grid[0].size();

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(grid[i][j] == '1'){
        //             colors.push_back({i,j});
        //         }
        //     }
        // }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    counter++;
                    dfs(grid, i, j);
                }
            }

        }    
        return counter;    
    }
};