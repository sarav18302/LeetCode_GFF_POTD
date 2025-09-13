class Solution {
public:
    bool isValid(string s)
    {
        int cnt = 0;
        for(auto x:s)
        {
            if(x=='(')
            cnt++;
            if(x == ')')
            {
                if(cnt>0) cnt--;
                else
                return false;
            }
        }
        return !cnt;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_set<string>ht;
        q.push(s);
        vector<string>res;
        while(!q.empty())
        {
            string t = q.front();
            q.pop();
            if(ht.count(t)) continue;
            ht.insert(t);
            if(isValid(t))
            res.push_back(t);
            else if(res.empty())
            {
                for(int i =0;i<t.size();i++)
                {
                    if(t[i] == ')'|| t[i] == '(')
                    q.push(t.substr(0,i)+t.substr(i+1));
                }
            }
        }
        return res;
    }
};