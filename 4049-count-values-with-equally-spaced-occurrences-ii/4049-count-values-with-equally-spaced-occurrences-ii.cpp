class Solution {
public:
    int countSpecialIntegers(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        map<int,vector<int>>mp;
        for(int i =0;i<n;i++){
            mp[a[i]].push_back(i);
        }
        for(auto a :mp){
            vector<int>v = a.second;
            if(v.size()>=3){
                int dif = v[1]-v[0];
                bool p = true;
                for(int i =0;i<v.size()-1;i++){
                   if(v[i+1]-v[i]!=dif){
                    p= false;
                    break;
                   }
                }
                if(p) ans++;
            }
        }
        return ans;
        
        
        
    }
};