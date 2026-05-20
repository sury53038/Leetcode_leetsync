class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n, 0);  
        set<int>st;
        
        for(int i = 0; i < n; i++){
            st.insert(A[i]);
            for(int j = 0; j <= i; j++){
                if(st.find(B[j]) != st.end()){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};