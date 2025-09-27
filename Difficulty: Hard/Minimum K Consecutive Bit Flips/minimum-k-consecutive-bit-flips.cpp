class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> isFlipped(n,0);
        int flipcnt = 0, currflip = 0;
        for(int i =0;i<n;i++)
        {
           if(i>=k)
           currflip^=isFlipped[i-k];
           if((arr[i]^currflip)==0)
           {
               if(i+k>n) return -1;
               flipcnt++;
               currflip^=1;
               isFlipped[i] = 1;
           }
        }
        return flipcnt;
    }
};