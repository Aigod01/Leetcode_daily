class Solution {
public:
    void dfs(string &temp,int open,int close,int n, vector<string>&ans){
       
        if(open == n && close ==n){
            ans.push_back(temp);
        }

        if(open<n){
            temp+='(';
            dfs(temp,open+1,close,n,ans);
            temp.pop_back();
        }
        if(close<open){
            temp +=')';
            dfs(temp,open,close+1,n,ans);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp ="";
        dfs(temp,0,0,n,ans);
        return ans;


    }
};