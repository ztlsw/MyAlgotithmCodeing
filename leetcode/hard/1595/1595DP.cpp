class Solution 
{
public:
    int dp[13][1<<13];
    int minn[13];

    int connectTwoGroups(vector<vector<int>>& cost) 
    {
        int n = cost.size(), m = cost[0].size();
        memset(minn,0x3f3f3f,sizeof(minn));
        memset(dp,0x3f3f3f,sizeof(dp));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                minn[j] = min(minn[j],cost[i][j]);
            }
        }
        dp[0][0] = 0;
        for(int i = 0;i<n;i++)
        {
            for(int mask = 0;mask<(1<<m);mask++)
            {
                for(int j = 0;j<m;j++) dp[i+1][mask|(1<<j)] = min(dp[i+1][mask|(1<<j)],dp[i][mask] + cost[i][j]);
                if(i == n-1)
                {
                    for(int mask2 = mask;mask2;mask2 = (mask2-1)&mask)
                    {
                        int cnt = 0;
                        for(int j = 0;j<m;j++)
                        {
                            if(!(mask2 & (1<<j)))
                            {
                                cnt += minn[j];
                            }
                        }
                        dp[i+1][mask] = min(dp[i+1][mask],dp[i+1][mask2] + cnt);
                    }
                }
            }
        }
        return dp[n][(1<<m)-1];
    }
};