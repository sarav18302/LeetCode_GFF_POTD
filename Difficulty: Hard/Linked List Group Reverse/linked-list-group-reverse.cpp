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
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || head->next == NULL)
        return head;
        Node * curr = head,*prev = NULL;
        Node* temp = NULL;
        int cnt = 0;
        while(curr && cnt <k)
        {
             temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        if(temp!=NULL)
        head->next = reverseKGroup(temp,k);
        return prev;
        
    }
};