class Solution {
  public:
  void merge(vector<int> &arr, int x, int low,int mid,int high)
  {
      vector<int>left(arr.begin()+low, arr.begin()+mid+1);
      vector<int>right(arr.begin()+mid+1, arr.begin()+high+1);
      int i =0, j =0, k =low;
      int n1 = left.size(), n2 = right.size();

      while(i<n1 && j<n2)
      {
          if(abs(x-left[i]) >abs(x-right[j]))
          {
              arr[k++] = right[j++];
          }
          else
          arr[k++] = left[i++];
      }
      while(i<n1)
      arr[k++] = left[i++];
      while(j<n2)
      arr[k++] = right[j++];
  }
    void mergesort(vector<int> &arr, int x, int low,int high)
    {
        if(low<high)
        {
            int mid = (low+high)/2;
            mergesort(arr,x,low,mid);
            mergesort(arr,x,mid+1,high);
            merge(arr,x,low,mid,high);
        }
    }
    void rearrange(vector<int> &arr, int x) {
        // code here
        mergesort(arr,x,0,arr.size()-1);
    }
};