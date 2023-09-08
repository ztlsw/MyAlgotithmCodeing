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
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> v[300];
        vector<string> ans;
        int now = 0;
        int nowlen = words[0].size();
        v[now].push_back(words[0]);
        for(int i = 1;i<words.size();i++)
        {
            if(nowlen+words[i].size()+1<=maxWidth) nowlen+=words[i].size()+1;
            else
            {
                now++;
                nowlen = words[i].size();
            }
            v[now].push_back(words[i]);
        }
        for(int i = 0;i<now;i++)
        {
            int n = v[i].size();
            string lim;
            if(n == 1)
            {
                lim+=v[i][0];
                while(lim.size()<maxWidth) lim+=" ";
                ans.push_back(lim);
                continue;
            }
            int lne = 0;
            for(int j = 0;j<n;j++) lne+=v[i][j].size(); 
            int blk = (maxWidth-lne)/(n-1);
            int yv = (maxWidth-lne)%(n-1);
            for(int j = 0;j<n-1;j++)
            {
                lim+=v[i][j];
                for(int k = 1;k<=blk;k++) lim+=" ";
                if(yv)
                {
                    lim+=" ";
                    yv--;
                }
            }
            lim+=v[i][n-1];
            ans.push_back(lim);
        }
        int n = v[now].size();
        string lim;
        for(int j = 0;j<n-1;j++)
        {
            lim+=v[now][j];
            lim+=" ";
        }
        lim+=v[now][n-1];
        while(lim.size()<maxWidth) lim+=" ";
        ans.push_back(lim);
        for(int i = 0; i<=now;i++)
        {
            cout<<ans[i].size()<<endl;
        }
        return ans;
    }
};


int main()
{
    Solution A;
    vector<string> vec = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    A.fullJustify(vec,16);
    return 0;
}