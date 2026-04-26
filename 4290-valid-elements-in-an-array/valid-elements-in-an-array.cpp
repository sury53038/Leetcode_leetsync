class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int greatest = INT_MIN;
        vector<int>ans;
        int smallest = INT_MIN;
        vector<int>visited(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > greatest && visited[i] == 0){
                greatest = nums[i];
                ans.push_back(nums[i]);
                visited[i] = 1;
            }
        }
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        vector<int>ans2;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] > smallest){
                smallest = nums[i];
                if(visited[i] == 0){
                    ans2.push_back(nums[i]);
                    visited[i] = 1;
                }
                
                
            }
        }
        for(int i = 0; i < ans2.size(); i++){
            cout<<ans2[i]<<" ";
        }
        for(int i = ans2.size()-1; i >= 0; i--){
            ans.push_back(ans2[i]);
        }
        return ans;
    }
};