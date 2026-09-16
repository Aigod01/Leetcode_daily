class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;

            long long inv = 1;
            long long base = i;
            long long p = MOD - 2;

            while (p) {
                if (p & 1)
                    inv = inv * base % MOD;
                base = base * base % MOD;
                p >>= 1;
            }

            ans = ans * inv % MOD;
        }

        return ans;
    }
};