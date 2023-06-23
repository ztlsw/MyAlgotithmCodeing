#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<cctype>
using namespace std;
class Solution 
{
public:
    int maximumValue(vector<string>& strs) 
    {
        int len = strs.size();
        int maxx = -1;
        for(int i = 0;i<len;i++)
        {
            int num = 0;
            bool flag = 0;
            for(int j = 0;j<strs[i].size();j++)
            {
                if(!isdigit(strs[i][j]))
                {
                    flag  = 1;
                    break;
                }
                num = num*10+strs[i][j]-'0';
            }
            if(flag) maxx = max(maxx,strs[i].size());
            else maxx = max(maxx,num);
        }
        return maxx;
    }
};