class Solution {
public:
    int nextGreaterElement(int n) {

        string ans = to_string(n);
        next_permutation(ans.begin(), ans.end());

        long long num = stoll(ans);
        if (num > INT_MAX)
            return -1;
        if (num <= n)
            return -1;

        return (int)num;
    }

};