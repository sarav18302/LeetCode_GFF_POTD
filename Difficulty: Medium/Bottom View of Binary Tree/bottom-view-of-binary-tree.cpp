/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
       map<int,int>mp;
        queue<pair<Node*,int>> st;
        st.push({root,0});
        while(!st.empty())
        {
            Node* ele = st.front().first;
            int lvl = st.front().second;
            st.pop();
            mp[lvl]=ele->data;
            if(ele->left)
            st.push({ele->left,lvl-1});
            if(ele->right)
            st.push({ele->right,lvl+1});
        }
        vector<int> ans;
        for(auto [k,v]:mp)
        {
            ans.push_back(v);
        }
        return ans;
    }
};