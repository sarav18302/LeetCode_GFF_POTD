class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int i =0,j=0;
        int n1 = s1.size(),n2 = s2.size();
        while(i<n1 && j<n2)
        {
            if(s1[i] == s2[j])
            {
                i++;
            }
            j++;
        }
        if(i==n1)
        return true;
        return false;
    }
};