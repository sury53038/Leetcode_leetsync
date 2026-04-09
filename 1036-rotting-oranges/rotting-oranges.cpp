class Solution {
public:
    int fresh = 0;
    queue<pair<int,int>>q;

    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};

    int time = 0;

    void bfs(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            int qsize = q.size();
            bool rot = false;
            for(int i = 0; i < qsize; i++){
                pair<int,int> temp = q.front();
                q.pop();
                int r = temp.first;
                int c = temp.second;
                if(grid[r][c] == 2){
                    for(int i = 0; i < 4; i++){
                        int rr = dr[i] + r;
                        int cc = dc[i] + c;

                        if(rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == 1){
                            grid[rr][cc] = 2;
                            fresh--;
                            rot = true;
                            q.push({rr,cc});
                        }
                    }
                }
            }
            if(rot) time++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        
        bfs(grid);
        
        return(fresh == 0) ? time : -1;
    }
};