/*
class Node {
public:
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
    int dfs(Node* root, int & ans)
    {
        if(!root)
        return 0;
        int left = max(0,dfs(root->left,ans));
        int right = max(0,dfs(root->right,ans));
        ans = max(ans, left + right + root->data);
        return root->data +max(left,right);
        
    }
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;
    }
};