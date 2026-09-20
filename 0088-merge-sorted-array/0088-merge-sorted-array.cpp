class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        if (i < m) {
            for (int k = i; k < m; k++) {
                ans.push_back(nums1[k]);
            }
        }
        if (j < n) {
            for (int k = j; k < n; k++) {
                ans.push_back(nums2[k]);
            }
        }
        nums1 = ans;
    }
};