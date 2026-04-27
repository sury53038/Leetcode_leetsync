class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> dijkshtra(vector<vector<pair<int,long long>>>&adj, int src){
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;

        int n = adj.size();
        vector<long long>distances(n, LLONG_MAX);
        vector<long long>nosofpath(n, 0);

        distances[src] = 0;
        nosofpath[src] = 1;

        pq.push({0, src});

        while(!pq.empty()){
            auto[wt, src]  = pq.top();
            pq.pop();
            if(wt > distances[src]) continue;

            for(auto nbr : adj[src]){
                int nbr_info = nbr.first;
                long long nbr_wt = nbr.second;

                long long new_wt = nbr_wt + wt;
                
                if(new_wt < distances[nbr_info]){
                    distances[nbr_info]  =  new_wt;
                    nosofpath[nbr_info] = nosofpath[src];
                    pq.push({new_wt, nbr_info});
                }
                else if(new_wt == distances[nbr_info]){
                    nosofpath[nbr_info] = (nosofpath[nbr_info] + nosofpath[src]) % MOD;
                }
            }
        }
        return nosofpath;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>>adj(n);
        for(vector<int>vec : roads){
            int src = vec[0];
            int dst = vec[1];
            int wt = vec[2];

            adj[src].push_back({dst, wt});
            adj[dst].push_back({src, wt});
        }
        vector<long long>ans = dijkshtra(adj, 0);

        return ans[n-1] % (int)MOD;
    }

};