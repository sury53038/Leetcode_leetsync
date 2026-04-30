class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> arr = nums;

        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        
        int count = 0;
        int ans = 0;

        for(int i = 1; i < arr.size(); i++){
            if(nums[i-1]+ 1 == nums[i]){
                count++;
                ans = max(count, ans);
            }
            else if(nums[i-1] == nums[i]) continue;
            else count = 0;
        }
        return ans+1;
    }
};