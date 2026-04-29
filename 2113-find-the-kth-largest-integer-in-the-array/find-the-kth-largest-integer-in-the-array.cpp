class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string& a, const string& b){
            if(a.size() != b.size()) return a.size() > b.size();
            return a > b;
        });
        for(int i =0; i < nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        return nums[k-1];
    }
};