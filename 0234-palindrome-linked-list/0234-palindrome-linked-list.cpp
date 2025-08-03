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
    bool check(ListNode* a, ListNode* b)
    {
        if(!a&&!b)
        return true;
        if(!a || !b)
        return false;
        return (a->val == b->val) && check(a->next,b->next);
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)
        return true;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* curr = head,*prev = NULL;
        while(curr->next!=mid)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr->next = prev;
        bool odd = check(curr,mid->next);
        bool even = check(curr,mid);
        return odd|| even;
    }
};