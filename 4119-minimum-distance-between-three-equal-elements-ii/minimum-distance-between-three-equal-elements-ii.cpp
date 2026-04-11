class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;

        int ans = INT_MAX;


        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto &it : mpp){
            auto ele = it.second;
            if(ele.size() < 3) continue;
            
            else{
                for(int i = 0; i + 2 < ele.size(); i++){
                    int temp = 2 * (ele[i+2] - ele[i]);
                    ans = min(ans, temp);
                }
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;

    }
};