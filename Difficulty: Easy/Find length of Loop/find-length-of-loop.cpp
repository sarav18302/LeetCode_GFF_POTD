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
        // Code here
        Node* slow = head, *fast = head;
        Node* start = NULL;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                start = slow;
                break;
            }
        }
        if(!start)
        return 0;
        int cnt = 1;
        Node* ref = start;
        start = start->next;
        while(start!=ref)
        {
            start = start->next;
            cnt++;
            
        }
        return cnt;
    }
};