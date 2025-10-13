/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  unordered_map<Node*,int>dp;
    int dfs(Node* root)
    {
        if(!root)
        return 0;
        if(dp[root]) return dp[root];
        int leftntk = dfs(root->left);
        int rightntk = dfs(root->right);
        int lltake = 0,lrtake = 0,rltake = 0,rrtake = 0;
        if(root->left)
        {
            lltake = dfs(root->left->left);
            lrtake = dfs(root->left->right);
        }
        
        if(root->right)
        {
            rltake = dfs(root->right->left);
            rrtake = dfs(root->right->right);
        }
        return dp[root] = max(root->data+lltake+lrtake+rltake+rrtake , leftntk+rightntk);
    }
    int getMaxSum(Node *root) {
        // code here
        return dfs(root);
    }
};