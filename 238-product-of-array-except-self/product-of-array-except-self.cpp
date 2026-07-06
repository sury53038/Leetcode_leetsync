class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
    
        int n = nums.size();
        vector<int>ans(n, 0);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i == j) continue;
        //         mul *= nums[j];
        //     }
        //     ans[i] = mul;
        //     mul = 1;
        // }

        vector<int>left(n, 0);
        vector<int>right(n, 0);
        left[0] = 1;
        right[n-1] = 1;
        for(int i = 1; i < n; i++){
            mul = nums[i-1]*mul;
            left[i] = mul;
        }
        mul = 1;
        for(int i = n-2; i >= 0; i--){
            mul = nums[i+1] * mul;
            right[i] = mul;
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                ans[i] = right[i];
            }
            if(i == n-1){
                ans[i] = left[n-1];
            }
            ans[i] = left[i]*right[i];
        }

        return ans;
    }
};