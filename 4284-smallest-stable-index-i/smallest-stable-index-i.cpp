class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>Max(n,0);
        vector<int>Min(n,0);
        int maxx = INT_MIN;
        int minn = INT_MAX;

        for(int i = 0; i < n; i++){
            maxx = max(maxx, nums[i]);
            Max[i] = maxx;
        }

        for(int i = 0; i < n; i++){
            minn = INT_MAX;
            for(int j = i; j < n; j++){
                minn = min(minn, nums[j]);
            }
            Min[i] = minn;
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            int score = Max[i] - Min[i];
            if(score <= k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};