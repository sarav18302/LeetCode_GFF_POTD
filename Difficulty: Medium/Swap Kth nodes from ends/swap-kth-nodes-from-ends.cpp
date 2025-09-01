/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        Node* temp1 = head;
        int cnt = 1;
        while(temp1&&cnt<k)
        {
            temp1 = temp1->next;
            cnt++;
        }
        if(!temp1)
        return head;
        Node* fast = head;
        for(int i =0;i<k;i++)
        {
            if(!fast) return head;
            fast = fast->next;
        }
        Node* slow = head;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(!slow)
        return head;
        swap(slow->data,temp1->data);
        return head;
        
    }
};