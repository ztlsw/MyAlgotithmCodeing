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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode * limlas = new ListNode();
        ListNode * limnxt = new ListNode();
        limlas=nullptr;
        limnxt =head->next;
        while(limnxt!=nullptr)
        {
            head->next=limlas;
            limlas=head;
            head=limnxt;
            limnxt=head->next;
        }
        head->next=limlas;
        return head;
    }
};