class Solution {
  public:
    int largestPrimeFactor(int n) {
        // code here
        int t = n;
        int res = 1;
        for(int i =2;i<=sqrt(t);i++)
        {
            // cout<<n<<" "<<i<<endl;
            if(n%i ==0)
            {
                // cout<<n<<endl;
                res = i;
                while(n%i==0)
                n= n/i;
                // cout<<n<<endl;
            }
        }
        if(n!=1) 
        {
            if(res<n)
            res = n;
        }
        return res;
    }
};