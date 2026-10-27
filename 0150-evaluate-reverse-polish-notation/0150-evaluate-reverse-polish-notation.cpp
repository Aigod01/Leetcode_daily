class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
       for(string ch : tokens) {
            if(all_of(ch.begin(), ch.end(), ::isdigit)||(ch.size() > 1 && ch[0] == '-')) {
                st.push(stoi(ch));
            }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(ch =="+"){
                st.push(a+b);
            }
            else if(ch =="-"){
                st.push(b-a);
            }
            else if(ch=="*"){
                st.push(a*b);
            }
            else{
                st.push(b/a);
            }
        }
       }
       return st.top();
        
    }
};