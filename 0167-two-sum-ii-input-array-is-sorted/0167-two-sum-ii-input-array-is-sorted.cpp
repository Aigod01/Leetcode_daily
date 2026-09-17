class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        map<int,int>mpp;
        for(int i = 0;i<n.size();i++){
            mpp[n[i]] = i+1;
        }
        for(int i =0;i<n.size();i++){
            if(mpp.find(target-n[i]) != mpp.end()){
                return {i+1,mpp[target-n[i]]};
            }
        }
        return {-1,-1};
        
    }
};