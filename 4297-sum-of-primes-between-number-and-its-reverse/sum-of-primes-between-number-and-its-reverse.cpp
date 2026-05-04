class Solution {
public:
    int reverse(int n){
        int x = n;
        int rev = 0;
        while(x){
            rev = rev*10 + (x % 10);
            x = x/10;
        }
        return rev;
    }
    
    bool isprime(int n){
        int counter = 0;

        if(n <= 1) return false;

        for(int i = 2; i*i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int sum = 0;


        for(int i = min(n, rev); i <= max(n, rev); i++){
            if(isprime(i)){
                cout<<i<<" ";
                sum += i;
            }
        }
        return sum;
    }
};