class Solution {
public:
    string largestGoodInteger(string num) {
        char ele = num[0];
        int cnt = 1;
        string ans =""; 
        for(int i = 1;i<num.size();i++)
        {
            if(ele != num[i])
            {
                ele = num[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            if(cnt == 3 && ele > ans[0])
            {
                ans = "";
                while(cnt--)
                {
                    ans+=ele;
                }
            }
        }
        return ans;
    }
};