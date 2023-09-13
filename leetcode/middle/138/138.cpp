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
        Node *now = new Node(0);
        Node *ans = now;
        Node *headcp = head;
        Node *headlas = head;
        queue<Node*> que;
        while(headcp!=nullptr)
        {
            que.push(headcp);
            Node *lim = new Node(headcp->val);
            now->next = lim;
            now->next->random = headcp->next;
            headcp = headcp->next;
            headlas ->next = lim;
            headlas = headcp;
            now = now->next;
        }
        now = ans->next;
        headcp = head;
        headlas = head;
        while(headcp!=nullptr)
        {
            headlas = headlas->next->random;
            if(headcp->random!=nullptr) now->random = headcp->random->next;
            else now->random = nullptr;
            headcp = headlas;
            now = now->next;
        }
        Node *mynow = que.front();
        que.pop();
        while(!que.empty())
        {
            mynow->next = que.front();
            mynow = mynow->next;
            que.pop();
        }
        mynow->next = nullptr;
        return ans->next;
    }
};

int main()
{

    return 0;
}