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
    Node* merge(Node* x, Node* y)
    {
        if(!x)
        return y;
        if(!y)
        return x;
        
        Node* head = new Node(-1);
        if(x->data <= y->data)
        {
            head = x;
            head->next = merge(x->next,y);
        }
        else
        {
            head = y;
            head->next = merge(x,y->next);
        }
        return head;
    }
    Node* msort(Node* head)
    {
        if(!head || !head->next)
        return head;
        Node* slow = head, * fast = head->next;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node * mid = slow->next;
        slow->next = NULL;
        
        
        Node* left = msort(head);
        Node* right = msort(mid);
        return merge(left,right);
        // return head;
    }
    Node* mergeSort(Node* head) {
        // code here
        return msort(head);
        
    }
};