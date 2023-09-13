#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == nullptr) return nullptr;
        Node *headp = head;
        Node *now = new Node(0);
        now->next = head;
        while(headp!=nullptr)
        {
            Node *lim = new Node(headp->val);
            lim -> next = headp->next;
            headp->next = lim;
            headp = lim->next;
        }
        headp = head;
        while(headp != nullptr)
        {
            if(headp->random!=nullptr) headp->next->random = headp->random->next;
            headp = headp->next->next;
        }
        headp = head;
        Node *base = now;
        while(headp!=nullptr)
        {
            now->next = headp->next;
            headp->next = headp->next->next;
            now = now->next;
            headp = headp->next;
        }
        return base ->next;
    }
};