class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, len = 0;
        string temp = "";
        // if(s.size() == 1){
        //     return 1;
        // }
        while(j < s.size()){
            if(temp.find(s[j]) == string::npos){
                temp += s[j];
                j++;
            }
            else{
                len = max(len, (int)temp.size());
                while(1){
                    if(temp[0] != s[j]){
                        temp.erase(0,1);
                    }
                    else if(temp[0] == s[j]){
                        temp.erase(0,1);
                        break;
                    }
                }
                temp += s[j];
                j++;
            }
        }
        len = max(len, (int)temp.size());
        return len;
    }
};
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<bool>chars(256,0);
//         int i = 0, j = 0, len = 0;
//         while(j < s.size()){

//             while(chars[s[j]]){
//                 chars[s[i]] = 0;
//                 i++;
//             }
//             chars[s[j]] = 1;
//             len = max(len, j - i + 1);
//             j++;
//         }
//         return len;
//     }
// };