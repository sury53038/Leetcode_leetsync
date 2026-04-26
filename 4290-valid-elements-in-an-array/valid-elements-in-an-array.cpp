class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            bool right = true;
            bool left = true;
            for(int j = 0; j < i; j++){
                if(nums[j] >= nums[i]) {
                    left = false;
                    break;
                }
            }

            if(!left){
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j] >= nums[i]){
                        right = false;
                        break;
                    }
                }
            }

            if(left || right) ans.push_back(nums[i]);
        }
        return ans;
    }
};