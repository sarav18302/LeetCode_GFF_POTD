class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int i = 1,cnt=0;
        while(n>0)
        {
            if(n&1)
            cnt++;
            n = n>>1;
        }
        return cnt;
    }
};