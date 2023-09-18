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
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        int dp[1010][2][110];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<=k+1;i++)  dp[0][1][i] = -1e9+7;
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<=min(k,n/2);j++)
            {
                dp[i+1][1][j] = max(dp[i][0][j]-prices[i],dp[i][1][j]);
                dp[i+1][0][j+1] = max(dp[i][1][j]+prices[i],dp[i][0][j+1]);
            }
        }
        int anss = 0;
        for(int i = 1;i<=k+1;i++) anss = max(anss,dp[n][0][i]);
        return anss;
    }
};


int main()
{
    Solution a;
    vector<int> prices = {3,2,6,5,0,3};
    cout<<a.maxProfit(2,prices)<<endl;
    return 0;
}