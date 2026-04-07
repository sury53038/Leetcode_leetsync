class Solution {
public:
    deque<int>dq;
    bool hasCycle = false;
    void dfs(vector<vector<int>>&adj, vector<int>&visited, int node){
        visited[node] = 1;


        for(int &nbr : adj[node]){
            if(visited[nbr] == 0){
                dfs(adj, visited, nbr);
                if(hasCycle) return;
            }
            else if(visited[nbr] == 1){
                hasCycle = true;
                return;
            }
        }
        visited[node] = 2;
        dq.push_front(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>visited(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>ans;

        for(int i = 0; i < adj.size(); i++){
            if(visited[i] == 0){
                dfs(adj, visited, i);
                if(hasCycle) return {};
            }
        }

        // for(int i = 0; i < visited.size(); i++){
        //     if(visited[i] == 0){
        //         return {};
        //     }
        // }

        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;

    }
};