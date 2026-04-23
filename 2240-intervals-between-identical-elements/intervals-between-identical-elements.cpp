class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>>mpp;
        vector<long long>ans(arr.size(), 0);

        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]].push_back(i);
        }
        

        for(auto par : mpp){
            vector<int>vec = par.second;
            int k = vec.size();

            long long total = 0;
            for(auto ind : vec) total += ind;

            long long leftsum = 0;

            for(int j = 0; j < k; j++){
                int ind = vec[j];

                long long rightsum = total - ind - leftsum;

                long long leftcount = j;
                long long rightcount = k - j - 1;

                long long left = (ind*leftcount) - leftsum;
                long long right = rightsum - (ind * rightcount);

                long long summ = left + right;
                ans[ind] = summ;
                leftsum += ind;
            }
        }
        return ans;
    }
};