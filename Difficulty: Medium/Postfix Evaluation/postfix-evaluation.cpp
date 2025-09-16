class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(int i =0;i<arr.size();i++)
        {
            if(arr[i] == "+")
            {
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                st.push(ele2+ele1);
            }
            else if(arr[i] == "-")
            {
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                st.push(ele2-ele1);
            }
            else if(arr[i] == "*")
            {
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                st.push(ele2*ele1);
            }
            else if(arr[i] == "/")
            {
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                st.push(floor((double)ele2/ele1));
            }
            else if(arr[i] == "^")
            {
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                st.push(pow(ele2,ele1));
            }
            else
            {
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
        
    }
};



// stack 2 3 1
// op *
// 3*1 ans = 3 stack 2 3
// op +
// 2+3 = 5  stck 5
// 9 stack 5 9
// op -
// 5 - 9 = -4