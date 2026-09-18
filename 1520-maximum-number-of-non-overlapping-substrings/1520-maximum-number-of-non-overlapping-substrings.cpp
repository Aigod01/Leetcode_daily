class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < s.size(); i++){
            if(first[s[i]-'a'] == -1)
                first[s[i]-'a'] = i;

            last[s[i]-'a'] = i;
        }

        vector<pair<int,int>> v;

        for(int c = 0; c < 26; c++){
            if(first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for(int i = l; i <= r; i++){
                if(first[s[i]-'a'] < l){
                    valid = false;
                    break;
                }

                r = max(r, last[s[i]-'a']);
            }

            if(valid)
                v.push_back({l,r});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for(auto p : v){
            if(p.first > end){
                ans.push_back(s.substr(p.first, p.second-p.first+1));
                end = p.second;
            }
        }

        return ans;
    }
};