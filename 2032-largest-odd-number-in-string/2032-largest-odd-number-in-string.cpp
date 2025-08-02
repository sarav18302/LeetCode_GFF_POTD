class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i =0;
        while(i<n && num[i]== '0')
        {
            i++;
        }
        string ans = "", t ="";
        for(;i<n;i++)
        {
            t+=num[i];
            if((int)(num[i])%2==1)
            ans = t;
        }
        return ans;
    }
};