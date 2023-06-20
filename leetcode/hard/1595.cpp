class Solution 
{
public:
    int dp[13][1<<13];
    int minn[13];
    int dfs(vector<vector<int>>& cost,int i,int mask,int n,int m)
    {
        if(dp[i][mask] != -1) return dp[i][mask];
        if(i == n)
        {
            int cnt = 0;
            for(int j = 0;j<m;j++)
            {
                if(!(mask & (1<<j)))
                {
                    cnt += minn[j];
                }
            }
            dp[i][mask] = cnt;
            return cnt;
        }
        else
        {
            int cnt = 0x3f3f3f3f;
            for(int j = 0;j<m;j++)
            {
                cnt = min(cnt,cost[i][j] + dfs(cost,i+1,mask|(1<<j),n,m));
            }
            dp[i][mask] = cnt;
            return cnt;
        }
    }


    int connectTwoGroups(vector<vector<int>>& cost) 
    {
        int n = cost.size(), m = cost[0].size();
        memset(minn,0x3f3f3f,sizeof(minn));
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                minn[j] = min(minn[j],cost[i][j]);
            }
        }
        return dfs(cost,0,0,n,m);
    }
};