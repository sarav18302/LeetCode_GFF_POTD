class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if(n==1)
        return (arr[0]%k) == 0? 0: k -(arr[0]%k);
        vector<int> mod;
        for(int i=0;i<n;i++)
        mod.push_back(arr[i]%k);
        sort(mod.begin(),mod.end());
        int luckycnt  =0;
        for(int i =0;i<n;i++)
        {
            if(mod[i] != 0)
            break;
            luckycnt++;
        }
        // cout<<luckycnt<<endl;
        if((n&1 && luckycnt >n/2)|| (n%2==0 && luckycnt>=n/2))
        return 0;
        int ans = 0;
        for(int i = n-1;i>=0;i--)
        {
            // cout<<mod[i]<<endl;
            if(mod[i]!=0)
            ans+=(k-mod[i]);
            luckycnt++;
            if((n&1 && luckycnt >n/2)||  (n%2==0 &&luckycnt>=n/2))
            break;
        }
        return ans;
        
    }

};