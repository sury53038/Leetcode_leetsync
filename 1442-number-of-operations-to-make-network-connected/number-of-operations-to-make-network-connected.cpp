class Solution {
public:
    void dfs(vector<vector<int>>&graph, vector<bool>&visited, int node){
        visited[node] = 1;
        for(auto nbr : graph[node]){
            if(!visited[nbr]){
                dfs(graph, visited, nbr);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        int count = -1;
        for(int i = 0; i < connections.size(); i++){
            int fst = connections[i][0];
            int scnd = connections[i][1];

            graph[fst].push_back(scnd);
            graph[scnd].push_back(fst);
        }

        vector<bool>visited(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(graph, visited, i);
            }
        }

        if(n - 1 > connections.size()) return -1;
        
        return count;
    }
};