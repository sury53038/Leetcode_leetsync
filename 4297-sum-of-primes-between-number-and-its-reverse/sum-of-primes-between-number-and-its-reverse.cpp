class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n){
            rev = rev*10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);

        int L = min(n, rev);
        int R = max(n, rev);

        vector<bool> isPrime(R + 1, true);

        // Edge cases
        if(R >= 0) isPrime[0] = false;
        if(R >= 1) isPrime[1] = false;

        // Sieve
        for(int i = 2; i * i <= R; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= R; j += i){
                    isPrime[j] = false;
                }
            }
        }

        int sum = 0;
        for(int i = L; i <= R; i++){
            if(isPrime[i]) sum += i;
        }

        return sum;
    }
};