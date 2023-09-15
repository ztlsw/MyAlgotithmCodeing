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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head == nullptr) return nullptr;
        ListNode *mummyl = new ListNode();
        ListNode *mu1head = mummyl;
        ListNode *mummy2 = new ListNode();
        ListNode *mu2head = mummy2;
        while(head!=nullptr)
        {
            if(head->val<x)
            {
                mummyl->next = head;
                head = head->next;
                mummyl = mummyl->next;
            }
            else
            {
                mummy2->next = head;
                head = head->next;
                mummy2 = mummy2->next;
            }
        }
        mummy2->next = nullptr;
        mummyl->next = mu2head->next;
        delete mu2head;
        return mu1head->next;
    }
};