/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode * head)
    {
        ListNode* curr = head, *prev = NULL;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* a = reverse(l1), *b = reverse(l2);
        ListNode* a = l1, *b = l2;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int carry =0;
        while(a&&b)
        {
            int sum = a->val+b->val+carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            // cout<<sum%10<<endl;
            curr->next = temp;
            curr = temp;
            a = a->next;
            b = b->next;
        }
        while(a)
        {
            int sum = a->val+carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            // cout<<sum%10<<endl;
            curr->next = temp;
            cout<<curr->next->val<<endl;
            curr= temp;
            a = a->next;
        }
        while(b)
        {
            int sum = b->val+carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            // cout<<sum%10<<endl;
            curr->next = temp;
            curr= temp;
            b = b->next;
        }
        if(carry>0)
        {
            ListNode* temp = new ListNode(carry);
            // cout<<carry<<endl;
            curr->next = temp;
            curr = temp;
        }
        return head->next;
    }
};