class Solution {
public:
    int threshold;
    vector<int>dijkshtra(vector<vector<pair<int,int>>>&adj, int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        int n = adj.size();

        vector<int>distances(n, INT_MAX);

        distances[src] = 0;
        pq.push({src, 0});

        while(!pq.empty()){
            auto pr = pq.top();
            pq.pop();

            int node = pr.first;
            int dist_of_node_from_src = pr.second;

            for(auto nbr : adj[node]){
                int nbr_node = nbr.first;
                int weight = nbr.second;

                int new_dist = dist_of_node_from_src + weight;
                if(new_dist > threshold) continue;

                if(new_dist < distances[nbr_node]){
                    distances[nbr_node] = new_dist;
                    pq.push({nbr_node, new_dist});
                }
            }
        }
        return distances;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        threshold = distanceThreshold;
        vector<vector<pair<int,int>>>adj(n);

        for(auto ele : edges){
            int s = ele[0];
            int d = ele[1];
            int wt = ele[2];

            adj[s].push_back({d, wt});
            adj[d].push_back({s, wt});
        }   
        int minn = INT_MAX;
        unordered_map<int,int>ump;
        for(int i = 0; i < n; i++){
            vector<int> distances = dijkshtra(adj, i);
            int count = 0;
            for (int d : distances) {
                if (d <= threshold) count++;
            }
            ump[i] = count;
            minn = min(minn, count);
        }
        int maxx = INT_MIN;
        for(auto ele : ump){
            if(ele.second == minn){
                maxx = max(ele.first, maxx);
            }
        }
        return maxx;
    }
};