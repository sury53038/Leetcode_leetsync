class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long counter = 0;
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        while(dvs <= dvd){
            long long temp = dvs;
            long long multiple = 1;

            while(dvd >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            counter += multiple;
        }

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            counter *= (-1);
        }
        return (int)counter;
    }
};