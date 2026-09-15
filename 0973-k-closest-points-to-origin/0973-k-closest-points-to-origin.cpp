class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& s, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ans;
        for(int i =0;i<s.size();i++){
            int d = (s[i][1]*s[i][1] + s[i][0]*s[i][0]);
            pq.push({d,{s[i][0],s[i][1]}});
        }
        while(k>0){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            k--;
            pq.pop();
        }
        return ans;

    }
};