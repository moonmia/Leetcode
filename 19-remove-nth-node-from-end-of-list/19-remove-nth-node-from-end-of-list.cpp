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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        
        for(int i=0; i<n+1; i++)
        {
            q = q->next;
        }
        
        while(q)
        {
            p=p->next;
            q=q->next;
        }
        
        ListNode* delnod = p->next;
        p->next = delnod->next;
        delete delnod;
        
        return dummy->next;
    }
};