class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<int>&state, int node){
        if(state[node] == 1){
            return false;
        }
        if(state[node] == 2){
            return true;
        }

        state[node] = 1;

        for(auto nbr : graph[node]){
            if(!dfs(graph, state, nbr)){
                return false;
            }
        }

        state[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>state(graph.size(), 0);

        vector<int>ans;

        for(int i = 0; i < graph.size(); i++){
            if(dfs(graph, state, i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};