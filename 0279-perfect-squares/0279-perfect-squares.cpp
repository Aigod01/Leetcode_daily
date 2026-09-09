class Solution {
public:
    int numSquares(int n) {

        int x = sqrt(n);
        if (x * x == n)
            return 1;

        for (int i = 1; i <= sqrt(n); i++) {
            int rem = n - i * i;
            int y = sqrt(rem);

            if (y * y == rem)
                return 2;
        }
        int temp = n;
        while (temp % 4 == 0)
            temp /= 4;

        
        if (temp % 8 == 7)
            return 4;
            
        return 3;
    }
};