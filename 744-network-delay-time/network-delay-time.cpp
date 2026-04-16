class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto &ele : times){
            int src = ele[0];
            int dest = ele[1];
            int time = ele[2];

            adj[src].push_back({time, dest}); 
        }

        queue<vector<int>>q;
        vector<int>time_taken(n+1, INT_MAX);

        time_taken[k] = 0;
        q.push({0, k});

        while(!q.empty()){
            auto f = q.front();
            q.pop();

            int tem = f[0];
            int node = f[1];

            for(auto &nbrs : adj[node]){
                int nbr_info = nbrs.second;
                int nbr_tem = nbrs.first;

                int new_tem = tem + nbr_tem;
                if(new_tem < time_taken[nbr_info]){
                    time_taken[nbr_info] = new_tem;
                    q.push({new_tem, nbr_info});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i < n+1; i++){
            if(time_taken[i] > maxi) maxi = time_taken[i];
        }
        if(maxi == INT_MAX) return -1;
        return maxi;
    }
};