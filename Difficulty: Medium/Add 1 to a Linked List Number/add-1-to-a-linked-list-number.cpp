/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head)
    {
        Node* curr = head, *prev = NULL;
        while(curr)
        {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        Node* curr = head;
        Node* newHead = reverse(head);
        Node* t = newHead;
        int carry = 1;
        while(t)
        {
           int sum = t->data+carry;
           carry = sum/10;
           t->data = sum%10;
           t = t->next;
        }
        if(carry>0)
        {
            Node* temp = new Node(carry);
            t = newHead;
            while(t->next)
            {
                t = t->next;
            }
            t->next = temp;
        }
        Node* p = reverse(newHead);
        return p;
        // return head of list after adding one
    }
};