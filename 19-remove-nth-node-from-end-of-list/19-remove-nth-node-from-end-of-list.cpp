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
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        
        for(int i=0; i<n+1; i++)
        {
            fast = fast->next;
        }
        
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;
        delete deleteNode;
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        
        return retNode;
    }
};