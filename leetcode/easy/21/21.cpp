#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *now1 = list1;
        ListNode *now2 = list2;
        ListNode *now = new ListNode(0,nullptr);
        ListNode *ans = now;
        while(now1!=NULL&&now2!=NULL)
        {
            if(now1->val<=now2->val)
            {
                now->next = now1;
                now = now->next;
                now1 = now1->next;
            }
            else
            {
                now->next = now2;
                now2 = now2->next;
                now = now->next;
            }
        }
        while(now1!=nullptr)
        {
            now->next = now1;
            now = now->next;
            now1 = now1->next;
        }
        while(now2!=nullptr)
        {
            now->next = now2;
            now = now->next;
            now2 = now2->next;
        }
        return ans->next;
    }
};