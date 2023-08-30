#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

class Solution 
{
    int dp[6001][2];
    int las[6001];
    bool vis[6001];
    int ans = 0x3f3f3f;
    public:
        inline void dfs(int pos,int step,int a,int b,int x,bool flag)
        {
            if(dp[pos][flag] <= step) return ;
            dp[pos][flag] = step;
            //las[pos] = lass;
            if(pos == x) return ;
            if(pos+a<=6000&&vis[pos+a]==0) dfs(pos+a,step+1,a,b,x,1);
            if(pos-b>=0&&vis[pos-b]==0&&flag) dfs(pos-b,step+1,a,b,x,0);
        }
        int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
        {
            memset(vis,0,sizeof(vis));
            memset(dp,0x3f,sizeof(dp));
            int len = forbidden.size();
            for(int i=0;i<len;i++) vis[forbidden[i]] = 1;
            dfs(0,0,a,b,x,1);
            if(dp[x][0]>1e6&&dp[x][1]>1e6) return -1;
            int lim = x;
            // while(lim)
            // {
            //     cout<<lim<<endl;
            //     lim = las[lim];
            // }
            //cout<<endl;
            return min(dp[x][0],dp[x][1]);
        }
};


int main()
{
    Solution  A;
    vector<int> vec = {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    cout<<A.minimumJumps(vec,29,98,80)<<endl;
    return 0;
}