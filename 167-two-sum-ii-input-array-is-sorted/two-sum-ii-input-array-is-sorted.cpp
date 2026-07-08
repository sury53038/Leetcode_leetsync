class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>mpp;
        int n = numbers.size();

        for(int i = 0; i < n; i++){
            if(mpp.find(target-numbers[i]) != mpp.end()){
                return {(mpp[target-numbers[i]])+1, i+1};
            }
            mpp[numbers[i]] = i;
        }
        return {};
    }
};