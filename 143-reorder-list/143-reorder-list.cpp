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
    void reorderList(ListNode* head) 
    {
        if(head == nullptr) return;
        
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse(l2);
        merge(l1,l2);
        
    }
    
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* dummy = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = dummy;
            dummy = curr;
            curr = next;
        }
        return dummy;
    }
    
    void merge(ListNode* l1, ListNode* l2)
    {
        ListNode* temp1;
        ListNode* temp2;
        while(l1 && l2)
        {
            temp1 = l1->next;
            temp2 = l2->next;
            
            l1->next = l2;
            l1 = temp1;
            
            l2->next = l1;
            l2 = temp2;
        }
    }
};