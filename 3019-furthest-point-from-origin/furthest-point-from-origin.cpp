class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;

        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'L') cnt1++;
            if(moves[i] == 'R') cnt2++;
            if(moves[i] == '_') cnt3++;
        }
        return abs(cnt1-cnt2)+cnt3;
    }
};