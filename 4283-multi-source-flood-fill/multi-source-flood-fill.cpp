class Solution {
public:
    void bfs(vector<vector<int>>&grid, queue<pair<int,int>>&q){
        vector<int> dr = {0,0,-1,1};
        vector<int> dc = {-1,1,0,0};
        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            int r, c;
            int size = q.size();

            map<pair<int,int>, int> nextColor;
            for(int i = 0; i < size; i++){
                auto[r,c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int rr = dr[k] + r;
                    int cc = dc[k] + c;

                    if(rr >= 0 && rr < m && cc >= 0 && cc < n){
                       if(grid[rr][cc] == 0){
                        nextColor[{rr,cc}] = max(nextColor[{rr,cc}], grid[r][c]);
                       }
                    }
                }
            }
            for (auto &it : nextColor) {
            int r = it.first.first;
            int c = it.first.second;
            int col = it.second;

            grid[r][c] = col;
            q.push({r,c});
        }
    }
        
        
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n, vector<int>(m,0));

        queue<pair<int,int>>q;

        for(auto ele : sources){
            int r = ele[0];
            int c = ele[1];
            int col = ele[2];
            grid[r][c] = col;
            q.push({r,c});
        }

        bfs(grid, q);

        return grid;        
    }
};