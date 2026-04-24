class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] != 0) return -1;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;

        dist[0][0] = 1;
        pq.push({0,0,1});

        vector<int>dr = {0,0,-1,1,1,1,-1,-1};
        vector<int>dc = {1,-1,0,0,1,-1,1,-1};

        while(!pq.empty()){
            auto[r,c,wt] = pq.top();
            pq.pop();

            if(r == m-1 && c == n-1) return wt;

            for(int i = 0; i < 8; i++){
                int rr = dr[i] + r;
                int cc = dc[i] + c;

                if(rr >= 0 && rr < n && cc >= 0 && cc < m && grid[rr][cc] == 0){
                    int new_wt = wt + 1;
                    
                    if(new_wt < dist[rr][cc]){
                        dist[rr][cc] = new_wt;
                        pq.push({rr, cc, new_wt});
                    }
                }
            }
        }
        return -1;
    }
};