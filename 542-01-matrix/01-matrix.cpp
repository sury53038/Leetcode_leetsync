class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = -1;
                }
            }
        }

        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};

        while(!q.empty()){
            int qsize = q.size();

            for(int i = 0; i < qsize; i++){
                pair<int,int>temp = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int rr = dr[k] + temp.first;
                    int cc = dc[k] + temp.second;

                    if(rr >=0 && rr < m && cc >= 0 && cc < n && mat[rr][cc] == 1 && ans[rr][cc] == -1){
                        ans[rr][cc] = ans[temp.first][temp.second] + 1;
                        q.push({rr,cc});
                    }
                }
            }
        }
        return ans;
    }
};