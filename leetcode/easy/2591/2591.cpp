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
            int lim = 8-x;
            int base = 0;
            while(p +  base * (x-1) < (children-base)*lim)
            {
                base++;
            }
            if(base == 1 && (p +  base * (x-1) - (children-base)*lim) == 3)
            {
                base ++;
            }
            cout<<base;
            return children - base > 0 ? children - base : 0;
        }
    }
};


int main()
{
    Solution sol;
    cout<<sol.distMoney(10,3);
    return 0;
}