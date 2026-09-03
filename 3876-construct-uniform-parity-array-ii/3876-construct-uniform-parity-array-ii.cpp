class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2 == 1){
            for(int i = 1;i<n;i++){
                for(int j = 0;j<i;j++){
                    if(nums1[i]%2 ==1 || (nums1[i]-nums1[j])%2==1) {
                        break;
                    }
                    else{
                        return 0;
                    }
                    
                }
            }
        }
        else{
            for(int i = 1;i<n;i++){
                for(int j = 0;j<i;j++){
                    if(nums1[i]%2 ==0 || (nums1[i]-nums1[j])%2==0) {
                        break;
                    }
                    else{
                        return 0;
                    }
                    
                }
            }
        }
        return 1;
        
    }
};