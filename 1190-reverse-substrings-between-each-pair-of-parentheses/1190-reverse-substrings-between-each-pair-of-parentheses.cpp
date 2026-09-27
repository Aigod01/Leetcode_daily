class Solution {
public:
    string reverseParentheses(string s) {
        bool inside = false;
        string temp="";

        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {

                string temp = "";
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                // reverse(temp.begin(), temp.end());
                for(char ch :temp){
                    st.push(ch);
                }
            }
            else{
                st.push(ch);
            }
        }

        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};