class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        int count = 0;

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int>q;

        vector<int>indegree(n);

        for(int i = 0; i < adj.size(); i++){
            for(int j = 0; j < adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp = q.front(); 
            q.pop();
            count++;
            for(auto it : adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return(count == n);
    }
};