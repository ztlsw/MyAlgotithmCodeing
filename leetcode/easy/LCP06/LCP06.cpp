#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<cctype>
using namespace std;
class Solution {
public:
    int minCount(vector<int>& coins) 
    {
        int ans = 0;
        for(int i = 0;i<coins.size();i++)
        {
            ans += (coins[i]+1)/2;
        }
        return ans;
    }
};