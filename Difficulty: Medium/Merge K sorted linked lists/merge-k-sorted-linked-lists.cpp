/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

struct CompareNode {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;  
    }
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node* ,vector<Node*>, CompareNode>pq;
        for(Node* x: arr)
        pq.push(x);
        
        Node* head = new Node(-1);
        Node* curr = head;
        while(!pq.empty())
        {
            Node* ele = pq.top();
            pq.pop();
            curr->next = ele;
            curr = ele;
            if(ele->next)
            pq.push(ele->next);
        }
        return head->next;
    }
};