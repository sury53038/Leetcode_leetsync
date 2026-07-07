class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int max_count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                continue;
            }
            if(nums[i-1] + 1 == nums[i]){
                count++;
                max_count = max(count, max_count);
            }
            else{
                count = 1;
            }
        }
        return max_count; 
    }
};