class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n<1000) return 0;
         if(n>=1000 ){
            long long a = min(n,999999LL)-999;
            ans += a;
        }
         if(n>=1000000LL){
            long long a = min(n,999999999LL)-999999;
            ans += 2*a;
        }
         if(n>=1000000000LL){
            long long a = min(n,999999999999LL)-999999999;
            ans += 3*a;
        }
        if(n>=1000000000000LL){
            long long a = min(n,999999999999999LL)-999999999999;
            ans += 4*a;
        }
        if (n >= 1000000000000000LL) {
            long long a = n - 999999999999999LL;
            ans += 5 * a;
        }
        return ans;
    }
    
};