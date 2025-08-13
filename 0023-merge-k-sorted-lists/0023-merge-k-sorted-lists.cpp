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
    struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // cout<<lists.size()<<endl;
        if(lists.size() == 1)
        return lists[0];

        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        priority_queue<ListNode*,vector<ListNode*>,compare> q;
        for(auto list:lists)
        {
            if(list)
            q.push(list);
        }
        // cout<<q.size()<<endl;
        while(!q.empty())
        {
            ListNode* ele = q.top();
            q.pop();
            // cout<<ele->val<<endl;
            curr->next = ele;
            curr = curr->next; 
            if (ele->next) {
                q.push(ele->next);
            }
        }
        curr->next = nullptr;
        return head->next;
    }
};