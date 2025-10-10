/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*>q;
        vector<int>ans;
        q.push(root);
        int flip = 0;
        while(!q.empty())
        {
            int t = q.size();
            vector<int> temp;
            for(int i =0;i<t;i++)
            {
                Node* ele = q.front();
                q.pop();
                temp.push_back(ele->data);
                if(ele->left)
                {
                    q.push(ele->left);
                }
                if(ele->right)
                q.push(ele->right);
            }
            if(flip)
            reverse(temp.begin(),temp.end());
            for(auto x: temp)
            ans.push_back(x);
            flip = ~flip;
        }
        return ans;
    }
};