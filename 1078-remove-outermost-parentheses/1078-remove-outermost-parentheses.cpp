class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int in = 0;
        int n = s.size();
        string ans ="";
        for(int i =0;i<n;i++)
        {
            st.push(s[i]);
            if(s[i] == '(')
            {
                in++;
            }
            else
            {
                in--;
                if(in == 0)
                {
                    st.pop();
                    string temp ="";
                    while(!st.empty() && in<=0)
                    {
                        char t = st.top();
                        st.pop();
                        if(t=='(')
                        in++;
                        else
                        in--;
                        if(in<=0)
                        temp+=t;
                    }
                    in--;
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                }
            }
        }
        return ans;
    }
};