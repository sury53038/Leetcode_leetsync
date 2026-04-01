class Solution {
public:
    int longestCycleLen = -1;

    void dfsFindLongest(int cycleLen, int node, vector<int>&currPath, vector<int>&visited, vector<int>&edges){
        cycleLen++;
        visited[node] = 1;
        currPath[node] = cycleLen;

        int nbr = edges[node];

        if(nbr != -1){
            if(!visited[nbr]){
                dfsFindLongest(cycleLen, nbr, currPath, visited, edges);
            }

            else if(currPath[nbr] != 0){
                int currCycleLen = currPath[node] - currPath[nbr] + 1;
                longestCycleLen = max(currCycleLen, longestCycleLen);
            }
        }
        currPath[node] = 0;
    }


    int longestCycle(vector<int>& edges) {
        vector<int>visited(edges.size(), 0);

        vector<int>currPath(edges.size(), 0);

        for(int i = 0; i < edges.size(); i++){
            if(!visited[i]){
                dfsFindLongest(0, i, currPath, visited, edges);
            }
        }
        return longestCycleLen;
    }
};