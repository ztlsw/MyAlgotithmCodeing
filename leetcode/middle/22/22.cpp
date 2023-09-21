#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution {
public:
    inline void dfs(vector<string> &ans,string &lim,int len,int num)
    {
        if(lim.size() == len)
        {
            if(num == 0) ans.push_back(lim);
            return ;
        }
        if(num == 0)
        {
            lim+='(';
            dfs(ans,lim,len,num+1);
            lim.pop_back();
            return ;
        }
        lim+='(';
        dfs(ans,lim,len,num+1);
        lim[lim.size()-1] = ')';
        dfs(ans,lim,len,num-1);
        lim.pop_back();
        return ;
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string lim;
        int num = 0;
        lim = "(";
        dfs(ans,lim,n*2,1);
        return ans;
    }
};