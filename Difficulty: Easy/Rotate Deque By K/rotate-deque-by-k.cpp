class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n = dq.size();
        if(type == 1)
        {
            for(int i =0;i<k;i++)
            {
                int ele = dq.back();
                dq.pop_back();
                dq.push_front(ele);
            }
        }
        else
        {
            for(int i =0;i<k;i++)
            {
                int ele = dq.front();
                dq.pop_front();
                dq.push_back(ele);
            }
        }
        
    }
};