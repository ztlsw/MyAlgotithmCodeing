#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#define ll long long
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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k == 1) return head;
        ListNode *headnow = head;
        ListNode *limhead = head;
        ListNode *nowpos = head;
        ListNode *pre = head;
        ListNode *laspos = head;
        ListNode *grouptail = nullptr;
        ListNode *test = head;
        int tot = 0;
        while(headnow!=nullptr) 
        {
            tot++;
            headnow = headnow->next;
        }
        tot/=k;
        int limk;
        //cout<<tot;
        while(tot--)
        {
            limk = k;
            while(limk--)
            {
                if(limk == k-1)
                {
                    limhead = nowpos;
                    laspos = limhead;
                    nowpos = nowpos->next;
                }
                else if(limk == 0)
                {
                    limhead->next = nowpos->next;
                    nowpos->next = laspos;
                    if(headnow == nullptr) headnow = nowpos;
                    if(grouptail!=nullptr) grouptail->next = nowpos;
                    grouptail = limhead;
                    nowpos = limhead->next;
                }
                else
                {
                    pre = nowpos->next;
                    nowpos->next = laspos;
                    laspos = nowpos;
                    nowpos = pre;
                }
            }
        }
        return headnow;
    }
};


int main()
{
    Solution a;
    ListNode *head = new ListNode(1);
    ListNode *now = head;
    for(int i = 2;i<=6;i++)
    {
        now->next = new ListNode(i);
        now = now->next;
    }
    ListNode *lim = a.reverseKGroup(head,2);
    while(lim!=nullptr)
    {
        cout<<lim->val<<" ";
        lim = lim->next;
    }
    return 0;
}