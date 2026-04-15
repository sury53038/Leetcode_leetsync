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
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;

        vector<vector<int>>costs(n, vector<int>(k+2, INT_MAX));

        costs[src][0] = 0;

        pq.push({0, src, 0});

        while(!pq.empty()){
        
            auto[wt, node, stops] = pq.top();
            pq.pop();

            if(node == dst) return wt;

            if(stops > k) continue;

            for(auto &nbr : adj[node]){
                int nbr_info = nbr.first;
                int nbr_cost = nbr.second;

                int new_cost = nbr_cost + wt;
                
                if(costs[nbr_info][stops+1] >  new_cost){
                    costs[nbr_info][stops+1] = new_cost;
                    pq.push({new_cost, nbr_info, stops+1});
                }
            }

        }
        return -1;

    }
};