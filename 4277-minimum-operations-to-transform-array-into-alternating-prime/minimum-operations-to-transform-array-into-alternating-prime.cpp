class Solution {
public:
    bool isprime(int ele){
        if(ele <= 1) return false;
        for(int i = 2; i*i <= ele; i++){
            if(ele%i == 0) return false;
        }
        return true;
    }

    int nearest_prime(int ele){
        int d = 1;
        while(true){
            // if(ele - d > 0 && isprime(ele-d)) return ele-d;
            if(isprime(ele+d)) return ele+d;
            d++;
        }
    }
    int nearest_non_prime(int ele){
        int d = 1;
        while(true){
            if(isprime(ele+d) == false) return ele+d;
            d++;
        }
    }
    
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                if(!isprime(nums[i])){
                    int nrst = nearest_prime(nums[i]);
                    ans += abs(nrst - nums[i]);
                }
            }
            else{
                if(isprime(nums[i])){
                    int nrst = nearest_non_prime(nums[i]);;
                    ans += abs(nrst-nums[i]);
                }
            }
        }  
        return ans;
    }
};