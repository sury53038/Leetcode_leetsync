class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>&adj){
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(col == 0){
                    if(dfs(it, 1, color, adj) == false) return false;
                }
                else{
                    if(dfs(it, 0, color, adj) == false) return false;
                }
                
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);

        for(int i = 0; i < v; i++){
            if(color[i] == -1){
               if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};