class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();
        int mini = 1e9;

        while(l <= r) {

            int left = 0;
            
            int right = 0;
            int sum = 0;

            while(right < n) {
                sum += nums[right];
                while(right - left + 1 > l) {
                    sum -= nums[left];
                    left++;
                }
                if(right - left + 1 == l) {
                    if(sum > 0) {
                        mini = min(mini, sum);
                    }
                }
                right++;
            }
            l++;
        }
        return mini == 1e9 ? -1 : mini;
    }
};