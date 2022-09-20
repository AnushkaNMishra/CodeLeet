class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto s: tokens){
            if(s.size()>1 || isdigit(s[0])){
                st.push(stoi(s));
            }
            else {
                auto x2=st.top();
                st.pop();
                auto x1=st.top();
                st.pop();
                if(s[0]=='+'){
                    x1+=x2;
                    st.push(x1);
                }
                else if(s[0]=='-'){
                    x1-=x2;
                    st.push(x1);
                }
                else if(s[0]=='/'){
                    x1/=x2;
                    st.push(x1);
                }
                else if(s[0]=='*'){
                    x1*=x2;
                    st.push(x1);
                }
            }
        }
        return st.top();
    }
};