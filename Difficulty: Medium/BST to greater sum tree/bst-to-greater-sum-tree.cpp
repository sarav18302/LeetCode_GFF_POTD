/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void dfs(Node *root,int &sum)
    {
        if(!root)
        return ;
        dfs(root->right,sum);
        int val = root->data;
        root->data = sum;
        sum+=val;
        dfs(root->left,sum);
        
    }
    void transformTree(Node *root) {
        // code here
        int sum = 0;
        dfs(root,sum);
    }
};