
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        if (sum == 0) {
            if (num == 1) return "0";
            return "";
        }

        string ans = "";

        while (num--) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        return ans;
    }
};
