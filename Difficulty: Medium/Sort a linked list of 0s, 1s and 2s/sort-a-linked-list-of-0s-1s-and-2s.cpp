/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zero_head = new Node(-1);
        Node* one_head = new Node(-1);
        Node* two_head = new Node(-1);
        
        Node * zc = zero_head, * oc = one_head, * tc =two_head;
        while(head!= NULL)
        {
            if(head->data == 0)
            {
                zc->next = head;
                zc = head;
            }
            else if(head->data == 1)
            {
                oc->next = head;
                oc = head;
            }
            else
            {
                tc->next = head;
                tc = head;
            }
            Node * t = head->next;
            head->next = NULL;
            head = t;
        }
        // cout<<oc->data<<" "<<tc->data<<" "<<zc->data<<endl;
        oc->next = two_head->next;
        zc->next = one_head->next;
        return zero_head->next;
    }
};