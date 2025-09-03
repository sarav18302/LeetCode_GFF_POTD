/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* pre = NULL;
        while(curr)
        {
            Node* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr->prev = temp;
            curr = temp;
        }
        return pre;
        
    }
};