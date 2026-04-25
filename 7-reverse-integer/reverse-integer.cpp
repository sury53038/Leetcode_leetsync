class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        

        int num = 0;
        while(x != 0){
            int digit = x % 10;
            x = x/10;

            if(num > INT_MAX/10 || num < INT_MIN/10) return 0;

            num = num * 10 + digit;
            
        }
        return num;
    }
};