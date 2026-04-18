class Solution {
public:
    int mirrorDistance(int n) {
        int num = n;
        int newNum = 0;
        while(num){
            int digit = num % 10;
            newNum = newNum * 10 + digit;
            num = num/10;
        }
        return abs(n-newNum);
    }
};