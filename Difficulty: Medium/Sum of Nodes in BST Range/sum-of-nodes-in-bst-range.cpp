/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int dfs(Node* root,int l, int r)
    {
        if(!root)
        return 0;
        int left = dfs(root->left,l,r);
        int right = dfs(root->right,l,r);
        if(root->data>=l && root->data<=r)
        return root->data +left+right;
        return left+right;
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        return dfs(root,l,r);
    }
};
