class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0;
        int ans = 0;
        for(char ch:s){
            if(ch =='('){
                opening++;
            }
            else{
                if(opening>0){
                    opening--;
                }
                else{
                    ans++;
                }
            }
        }
        return abs(opening+ans);
    }
    
};