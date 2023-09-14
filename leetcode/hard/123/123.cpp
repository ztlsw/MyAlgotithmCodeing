#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int dp[100010][2][4];
        int n = prices.size();
        memset(dp,-0x3f3f3f,sizeof(dp));
         dp[0][0][0] = 0;
         dp[0][1][2] = -1e9;
        for(int i = 0;i<n;i++)
        {
            dp[i+1][0][0] = 0;
            dp[i+1][1][0] = max(dp[i][0][0]-prices[i],dp[i][1][0]);
            dp[i+1][0][1] = max(dp[i][0][1],dp[i][1][0]+prices[i]);
            dp[i+1][1][1] = max(dp[i][0][1]-prices[i],dp[i][1][1]);
            dp[i+1][0][2] = max(dp[i][0][2],dp[i][1][1]+prices[i]);
            dp[i+1][1][2] = -1e9;
        }
        return max(max(0,dp[n][0][2]),dp[n][0][1]);
    }
};

int main()
{

    return 0;
}