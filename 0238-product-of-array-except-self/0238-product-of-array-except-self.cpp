class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suffi(n);

        vector<int> ans;

        pref[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i - 1] * nums[i];
        }
        suffi[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffi[i] = suffi[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? 1 : pref[i - 1];
            int right = (i == n - 1) ? 1 : suffi[i + 1];
            ans.push_back(left * right);
        }
        return ans;
    }
};