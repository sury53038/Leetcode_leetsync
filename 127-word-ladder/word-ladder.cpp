class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(),  wordList.end());

        int n = wordList.size();
        int m = wordList[0].size();

        queue<pair<string,int>>q;

        if(dict.find(endWord) == dict.end()) return 0;

        q.push({beginWord, 1});

        while(!q.empty()){
            auto[wordd, lev] = q.front();
            q.pop();
            

            for(int j = 0; j < m; j++){
                string wor = wordd;
                for(int i = 0; i < 26; i++){
                    wor[j] = 'a' + i;
                    string new_ = wor;
                    if(new_ == endWord) return lev+1;
                    if(dict.find(new_) != dict.end()){
                        cout<<new_<<"  ";
                        q.push({new_, lev+1});
                        dict.erase(new_);
                    }
                }
            }
        }
        return 0;
    }
};