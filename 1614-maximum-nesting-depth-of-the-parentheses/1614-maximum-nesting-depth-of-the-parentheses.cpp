class Solution {
public:
    int maxDepth(string s) {
        int opening_parenthesis=0;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
                opening_parenthesis++;
                maxi=max(opening_parenthesis,maxi);
            }
            else if(s[i]==')'){
                opening_parenthesis--;
            }  
        }
        return maxi;
    }
};