class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }

        vector<long long>ans(n);
        for(auto ele : mpp){
            long long total = 0;
            vector<int>indx = ele.second;
            for(auto ind : indx) total += ind;
            
            long long  leftsum = 0;

            for(int i = 0; i < indx.size(); i++){
                int ind = indx[i];

                long long rightsum = total - leftsum - ind;
                
                long long leftcount = i;
                long long rightcount = indx.size() - i - 1;

                long long left = (ind * leftcount) - leftsum;
                long long right = rightsum - (ind * rightcount);

                ans[ind] = left + right;
                leftsum += ind;
            }
        }
        return ans;   
    }
};