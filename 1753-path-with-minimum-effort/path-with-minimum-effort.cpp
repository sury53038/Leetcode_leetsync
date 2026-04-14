class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
 
        int ans = INT_MAX, max_of_path = INT_MIN;

        int m = heights.size();
        int n = heights[0].size();

        vector<int> dr = {0,0,-1,1};
        vector<int> dc = {-1,1,0,0};

        vector<vector<int>> abs_dif(m, vector<int>(n, INT_MAX));

        abs_dif[0][0] = 0;

        pq.push({0,0,0});

        while(!pq.empty()){
            
            auto[wt, r, c] = pq.top();
            pq.pop();
            if(r == m-1 && c == n-1) return wt;

            for(int i = 0; i < 4; i++){
                int rr = dr[i] + r;
                int cc = dc[i] + c;

                if(rr >= 0 && rr < m && cc >= 0 && cc < n){
                    int dif = abs(heights[r][c] - heights[rr][cc]);
                    int newEffort = max(wt, dif);

                    if(abs_dif[rr][cc] > newEffort){
                        abs_dif[rr][cc] = newEffort;
                        pq.push({newEffort, rr, cc});
                    }
                    max_of_path = max(wt, dif);
                    ans = min(ans, max_of_path);
                }
            }
        }
        return 0;
    }
};