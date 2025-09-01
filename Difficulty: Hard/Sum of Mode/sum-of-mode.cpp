class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        map<int,int>mp;
        int n = arr.size();
        int cnt = 0, maxele = -1;
        int sum = 0;
        for(int i =0;i<n;i++)
        {
            mp[arr[i]]++;
            if(cnt < mp[arr[i]])
            {
                cnt = mp[arr[i]];
                maxele = arr[i];
            }
            else if(cnt == mp[arr[i]] && maxele > arr[i])
            {
                maxele = arr[i];
            }
            if(i>=k)
            {
                // cout<<arr[i-k]<<" ";
                mp[arr[i-k]]--;
                // if(mp[arr[i-k]]==0)
                // mp.erase(arr[i-k]);
                if(arr[i-k] == maxele)
                {
                    cnt-=1;
                    for(auto [k,v]:mp)
                    {
                        if(v>cnt)
                        {
                            cnt = v;
                            maxele = k;
                        }
                        else if(v == cnt && k <maxele)
                        {
                            maxele = k;
                        }
                    }
                }
                // cout<<maxele<<" "<<i<<endl;
                
            }
           
            if(i>=k-1)
            {
                //  cout<<maxele<<" "<<i<<endl;
                 sum+=maxele;
            }
            
            
        }
        return sum;
    }
};