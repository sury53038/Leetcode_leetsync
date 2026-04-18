class Solution {
public:
    int mirrorDistance(int n) {
        int num = n;
        int newNum = 0;
        while(num > 0){
            newNum = newNum * 10 + (num % 10);
            num = num/10;
        }
        return abs(n-newNum);
    }
};