class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int j = i+1, k = n-1;
            while(j < k){
                if(nums[j] + nums[k] == -nums[i]){
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] > -nums[i]){
                    k--;
                }
                else if(nums[j] + nums[k] < -nums[i]){
                    j++;
                }
            }
        }
        vector<vector<int>> finaal;
        for(vector<int> ele : ans){
            finaal.push_back(ele);
        }
        return finaal;
    }
};