/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* helper(int preStart,int postidx, int preEnd,vector<int> &pre, vector<int> &post)
    {
        if(preStart > preEnd)
        return NULL;
        
        Node* root = new Node(pre[preStart]);
        if(preStart == preEnd)
        return root;
        
        int j = postidx;
        while(post[j]!=pre[preStart+1])
        j++;
        
        int num = j-postidx+1;
        root->left = helper(preStart+1,postidx,preStart+num,pre,post);
        root->right = helper(preStart+num+1,j+1,preEnd,pre,post);
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        return helper(0,0,pre.size()-1,pre,post);
    }
};
// N L R
// L R N