class Solution {
public:
    bool validDigit(int n, int x) {
        if(n == 0) return false;
        bool cond1 = false;

        int num = n;
        int digcount = 0;
        int rev = 0;
        while(num > 0){
            int digit = num % 10;
            if(digit == x) cond1 = true;
            digcount++;
            rev = rev*10 + digit;
            num /= 10;
        }
        if(digcount == 1 && cond1 == true) return false;
        int p = rev % 10;

        if(p != x && cond1== true) return true;
        return false;
        
    }
};