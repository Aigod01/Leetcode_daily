class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, int sum,
               vector<vector<int>>& ans, vector<int>& temp) {

        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (i >= candidates.size() || sum > target)
            return;

        temp.push_back(candidates[i]);
        solve(candidates, target, i, sum + candidates[i], ans, temp);

            temp.pop_back();

         (solve(candidates, target, i + 1, sum, ans, temp));
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;
        solve(candidates,target,0,0,ans,temp);
        return ans;
    }
};