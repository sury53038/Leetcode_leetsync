class Solution {
public:
    int reverse(int num){
        int newNum = 0;
        while(num > 0){
            newNum = newNum * 10 + (num%10);
            num = num/10;
        }
        return (newNum*1);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,int>mpp;

        for(int i = 0; i < nums.size(); i++){
            if(mpp.find(nums[i]) != mpp.end()){
                ans = min(ans, abs(i-mpp[nums[i]]));
            }
            int ele = reverse(nums[i]);
            mpp[ele] = i;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};