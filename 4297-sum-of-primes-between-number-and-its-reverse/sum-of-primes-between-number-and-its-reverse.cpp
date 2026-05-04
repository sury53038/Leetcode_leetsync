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
    
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int sum = 0;        

        int s = min(rev, n);
        int l = max(rev, n);

        vector<bool>isprime(l+1, true);

        isprime[0] = isprime[1] = false;

        for(int i = 2; i*i <= l; i++){
            if(isprime[i]){
                for(int j = i+i; j <= l; j += i){
                    isprime[j] = false;
                }
            }
        }

        for(int i = s; i <= l; i++){
            if(isprime[i] == true){
                sum += i;
            }
        }
        return sum;
    }
};