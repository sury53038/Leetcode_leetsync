class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        while(k > 0){
            int temp = INT_MIN;
            int cnt = 0;
            for(auto it : mpp){
                if(it.second > temp){
                    temp = it.second;
                    cnt = it.first;
                }
            }
            mpp[cnt] = -1;
            ans.push_back(cnt);
            k--;
        }
        return ans;
    }
};