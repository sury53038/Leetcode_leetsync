class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int d, wt,s;
        for(auto &f : flights){
            s = f[0];
            d = f[1];
            wt = f[2];

            adj[s].push_back({d, wt});
        }
        queue<pair<int,int>>pq;

        vector<int>costs(n, INT_MAX);

        costs[src] = 0;

        int stops = 0;

        pq.push({0, src});

        while(!pq.empty() && stops <= k){
            int size = pq.size();
            for(int i = 0; i < size; i++){
                auto[wt, node] = pq.front();
                pq.pop();

                for(auto &nbr : adj[node]){
                    int nbr_info = nbr.first;
                    int nbr_cost = nbr.second;

                    int new_cost = nbr_cost + wt;
                    
                    if(costs[nbr_info] >  new_cost){
                        costs[nbr_info] = new_cost;
                        pq.push({new_cost, nbr_info});
                    }
                }
            }
            stops++;
        }
        if(costs[dst] == INT_MAX) return -1;
        return costs[dst];
    }
};