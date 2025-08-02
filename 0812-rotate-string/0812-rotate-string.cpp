class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n!=goal.size())
        return false;
        int i =0,left =0,right=0;
        while(i<n)
        {
            while(i<n && s[i] !=goal[left] ) i++;
            if(i==n) return false;
            int idx = i;
            while(left<n)
            {
                int ind = idx%n;
                if(goal[left] !=s[ind])
                break;
                idx++;
                left++;
            }
            if(left ==n)
            return true;
            left =0;
            i++;
        }
        return false;
    }
};