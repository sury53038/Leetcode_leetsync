class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        
        queue<pair<int,int>> q;
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Step 1: push boundary O
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        grid[i][j] = 1; // mark visited
                    }
                }
            }
        }

        // Step 2: BFS (mark safe region)
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int rr = temp.first + dr[k];
                int cc = temp.second + dc[k];

                if(rr >= 0 && rr < m && cc >= 0 && cc < n 
                   && board[rr][cc] == 'O' && grid[rr][cc] == 0){
                    
                    grid[rr][cc] = 1; // FIX
                    q.push({rr,cc});
                }
            }
        }

        // Step 3: convert surrounded regions
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && grid[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};