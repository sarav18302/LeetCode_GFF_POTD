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
    int lengthOfLoop(Node *head) {
        // code here
        Node * slow = head, * fast = head;
        bool found = false;
        while(fast&& fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                found = true;
                break;
            }
        }
        // cout<<slow->data<<" "<<fast->data<<endl;
        Node* temp = slow;
        slow = slow->next;
        int cnt = 1;
        if(found)
        {
            while(slow!=temp)
            {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
        return 0;
        
    }
};