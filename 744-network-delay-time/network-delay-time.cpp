class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int s = times[i][0];
            int d = times[i][1];
            int wt = times[i][2];

            adj[s].push_back({wt, d});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();

            for(auto &nbr : adj[node]){
                int nbr_info = nbr.second;
                int nbr_wt = nbr.first;

                int new_wt = nbr_wt + wt;

                if(new_wt < dist[nbr_info]){
                    dist[nbr_info] = new_wt;
                    pq.push({new_wt, nbr_info});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i < n+1; i++){
            if(dist[i] > ans){
                ans = dist[i];
            }   
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};