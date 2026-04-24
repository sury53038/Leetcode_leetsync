class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string check= "";
        for(string st : words){
            check += st[0];
        }
        return (check == s);
    }
};