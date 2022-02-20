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
private:
    ListNode* mergeTwoLists(ListNode*  list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 == nullptr ? list2 : list1;
        return dummy->next;
    }
public:
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right) return lists[left];
        if(left > right) return nullptr;
        int mid = (left+right)>>1;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid+1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return merge(lists, 0, lists.size()-1);
    }
};