class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        sort(nums.begin(),nums.end());
        int count = 1;
        int ans = 0;
        int n = nums.size();
        if(n==0) return 0;
        if(n == 1 ) return 1;
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i]-1 == nums[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            ans = max(ans,count);
        }
        return max(ans,count);  
    }
};