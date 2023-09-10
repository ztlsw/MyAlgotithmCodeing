#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
class Solution {
public:
    int numberOfWays(string s, string t, long long k) 
    {
        string lim1;
        string lim2;
        string lim3;
        int x = 0;
        for(int i = 0;i<s.size();i++)
        {
            lim1 = s.substr(0,i+1);
            lim2 = s.substr(i+1,s.size()-i-1);
            lim3 = lim2+lim1;
            if(lim3 == t) x++;
        }
        if(x == 0) return 0;
        
    }
};