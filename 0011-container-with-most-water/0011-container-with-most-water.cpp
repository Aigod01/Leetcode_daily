class Solution {
public:

    int maxArea(vector<int>& height) {
        int l  = 0;
        int r = height.size()-1;
        int ans = 0;    
        while(l<r){
            int area = (r-l)*(min(height[r],height[l]));

            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
            ans = max(ans,area);
        }
        return ans;
    }
};