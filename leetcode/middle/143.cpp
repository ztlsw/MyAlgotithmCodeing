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
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return ;
        ListNode* lim = head;
        int tot=0;
        while(head->next!=nullptr)
        {
            head=head->next;
            tot++;
        }
        int flag=0;
        if(tot%2==0) flag++;
        tot=(tot+1)/2;
        tot+=flag;
        head=lim;
        ListNode * las = lim;
        while(tot--)
        {
            las = lim;
            lim=lim->next;
        }
        las ->next = nullptr;
        ListNode * rev1 = lim;
        ListNode * rev2 =nullptr;
        if(lim->next!=nullptr)
        {
            rev2 = lim->next;
            lim->next=nullptr;
        }
        while(rev2!=nullptr)
        {
            rev1=rev2->next;
            rev2->next=lim;
            lim=rev2;
            rev2=rev1;
        }
        rev2=lim;
        rev1=head;

        while(rev2!=nullptr&&rev1!=nullptr)
        {
            lim=rev1->next;
            rev1->next=rev2;
            las=rev2->next;
            rev2->next = lim;
            rev2 = las;
            rev1=lim;
        }
        return ;
    }
};
