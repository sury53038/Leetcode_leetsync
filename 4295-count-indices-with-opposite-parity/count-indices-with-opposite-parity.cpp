class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        bool parity = true;
        for(int i = 0; i < n; i++){
            int counter1 = 0;
            int counter2 = 0;

            if(nums[i] % 2 == 0) parity = true;
            else parity = false;

            for(int j = i+1; j < n;  j++){
                if(parity && nums[j] % 2 != 0){
                    counter1++;
                }
                else if(!parity && nums[j]%2 == 0){
                    counter2++;
                }
            }
            if(parity){
                ans.push_back(counter1);
            }
            else{
                ans.push_back(counter2);
            }
        }
        return ans;
    }
};