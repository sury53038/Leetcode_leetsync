class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        vector<vector<int>>grid(m, vector<int>(n));
        queue<pair<int,int>>q;

        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        grid[i][j] = 1;
                    }
                }
            }
        }

        

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int,int>temp = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int rr = dr[k] + temp.first;
                    int cc = dc[k] + temp.second;

                    if(rr >= 0 && rr < m && cc >= 0 && cc < n && board[rr][cc] == 'O' && grid[rr][cc] == 0){
                        grid[rr][cc] = 1;
                        q.push({rr,cc});
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == 'O' && grid[i][j] == 0){
                        board[i][j] = 'X';
                    }
                }
            } 
    }
};