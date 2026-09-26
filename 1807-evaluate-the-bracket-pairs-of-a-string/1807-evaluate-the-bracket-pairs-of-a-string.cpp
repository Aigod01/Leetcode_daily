class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        string temp ="";
        bool inside = false;
        unordered_map<string,string>mp;
        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }
        
        for(auto ch : s){

            if(ch == '('){
                temp ="";
                inside = true;

            }
            else if( ch == ')'){
                inside = false;
                if(mp.find(temp) != mp.end())
                    ans += mp[temp];
                else
                    ans += "?";
                
            }
            else{
                if(!inside){
                    ans+=ch;
                }
                else{
                    temp+=ch;
                }
            }
        }
        return ans;
        
    }
};