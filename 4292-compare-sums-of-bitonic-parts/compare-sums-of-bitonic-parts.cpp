class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int size = nums.size();
        long long rightsum = 0;
        long long leftsum = nums[0];
        for(int i = 1; i < size; i++){
            if(nums[i] >= nums[i-1]){
                leftsum += nums[i];
            }
            else{
                rightsum += nums[i-1];
            }
        }
        rightsum += nums[size-1];

        if(leftsum > rightsum) return 0;
        else if(rightsum > leftsum) return 1;
        return -1;
    }
};