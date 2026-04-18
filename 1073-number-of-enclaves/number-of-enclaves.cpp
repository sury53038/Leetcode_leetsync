class Solution {
public:
    void solutionFun(vector<vector<int>>&copy){
        queue<pair<int,int>>q;
        int n = copy.size();
        int m = copy[0].size();

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(copy[i][j] == 1){
                        q.push({i,j});
                    }
                }
            }
        }

        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            if(copy[r][c] == 0) continue;
            copy[r][c] = 0;
            for(int i = 0; i < 4; i++){
                int rr = dr[i] + r;
                int cc = dc[i] + c;

                
                if(rr >= 0 && rr < n && cc >= 0 && cc < m && copy[rr][cc] == 1){
                    q.push({rr,cc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        vector<vector<int>>copy = grid;
        int m = copy.size();
        int n = copy[0].size();
        
        // vector<vector<int>>visited(m, vector<int>(n,0));


        solutionFun(copy);

        int counter = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(copy[i][j] == 1){
                    counter++;
                }
            }
        }   

        return counter;        
    }
};