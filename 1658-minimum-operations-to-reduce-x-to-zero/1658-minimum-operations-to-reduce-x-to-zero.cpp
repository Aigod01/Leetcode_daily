class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n=nums.size();

        int l=0;
        int r=0;
        int sum=0;
        int ans=-1;

        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        int target=total-x;

        if(target<0) return -1;
        if(target==0) return n;

        while(r<n){

            sum+=nums[r];

            while(sum>target){
                sum-=nums[l];
                l++;
            }

            if(sum==target){
                ans=max(ans,r-l+1);
            }

            r++;
        }

        if(ans==-1) return -1;

        return n-ans;
    }
};