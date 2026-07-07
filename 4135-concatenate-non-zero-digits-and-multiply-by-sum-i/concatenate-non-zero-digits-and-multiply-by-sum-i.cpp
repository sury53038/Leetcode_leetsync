class Solution {
public:
    long long sumAndMultiply(int n) {
        long long new_num = 0;
        long long  sum = 0;
        while(n){
            int digit = n % 10;
            if(digit != 0){
                new_num = new_num*10 + digit;
                sum += digit;
            }
            n = n / 10;
        }
        long long temp = 0;
        while(new_num){
            int digit = new_num % 10;
            temp = temp * 10 + digit;
            new_num = new_num / 10;
        }
        return temp * sum;
    }
};