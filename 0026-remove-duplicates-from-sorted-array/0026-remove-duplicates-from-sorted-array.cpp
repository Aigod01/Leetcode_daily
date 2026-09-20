class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.insert(nums[i]);
        }
        int i = 0;
        for (auto it : ans) {
            nums[i] = it;
            i++;
        }

        return ans.size();
    }
};