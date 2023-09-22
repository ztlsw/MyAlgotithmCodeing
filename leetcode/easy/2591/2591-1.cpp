#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

class Solution {
public:
    int distMoney(int money, int children) 
    {
        if(children>money) return -1;
        int x = money / children;
        int p = money %children;
        if(x>=8)
        {
            if(x == 8&&p == 0) return children;
            else return children-1;
        }
        else
        {
            int x2 = money/8;
            int m = money%8;
            if(x2 == children-1&&m == 4) x2--;
            int non = children - x2-m;
            if(non<=0) return x2;
            int kk = non/7;
            if(non%7) kk++;
            return x2-kk;

        }
    }
};