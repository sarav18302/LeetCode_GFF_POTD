
class Solution {
  public:
    void merge(vector<pair<int,int>> &vec,vector<int>&ans,int low,int mid, int high)
    {
        // cout<<low<<" "<<high<<endl;
        vector<pair<int,int>> left,right;
        int n1 = mid+1-low, n2 = high-mid;
        for(int i =0;i<n1;i++)
        left.push_back(vec[low+i]);
        for(int i =0;i<n2;i++)
        right.push_back(vec[mid+1+i]);
        int i =0, j=0,k=low;
        while(i<n1 && j<n2)
        {
            // cout<<"In while loop"<<endl;
            if(left[i].first < right[j].first)
            {
                // cout<<"Here"<<endl;
                ans[left[i].second] += (n2-j);
                vec[k++] = left[i++];
            }
            else
            {
                vec[k++] = right[j++];
            }
        }
        while(i<n1)
        {
            vec[k++] = left[i++];
        }
        while(j<n2)
        {
            vec[k++] = right[j++];
        }
    }
    void mergesort(vector<pair<int,int>> &vec,vector<int>&ans,int low, int high )
    {
        if(low <high)
        {
            int mid = low+ (high-low)/2;
            mergesort(vec,ans,low,mid);
            mergesort(vec,ans,mid+1,high);
            merge(vec,ans,low,mid,high);
        }
        
    }
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n  = arr.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> vec;
        for(int i =0;i<n;i++)
        vec.push_back({arr[i],i});
        mergesort(vec,ans,0,n-1);
        vector<int> res;
        for(int i =0;i<indices.size();i++)
        {
            res.push_back(ans[indices[i]]);
        }
        // cout<<res.size()<<endl;
        // for(auto x:ans)
        // cout<<x<<" ";
        // cout<<endl;
        // for(auto x:vec)
        // cout<<x.first<<" ";
        // cout<<endl;
        return res;
    }
};