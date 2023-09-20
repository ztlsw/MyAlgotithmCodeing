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
        ListNode *next = head;
        for(int i = 0;i<k;i++)
        {
            if(next == nullptr)
            {
                return head;
            }
            next = next->next;
        }

        ListNode *middle = head,*front = reverseKGroup(next,k),*later = head->next;
        for(int i = 0;i<k;i++)
        {
            ListNode *tmp = middle;
            middle->next = front;
            front = tmp;
            middle = later;
            if(later!=nullptr) later = later->next;
        }
        return front;
    }
};