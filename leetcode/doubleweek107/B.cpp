#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
class Solution {
private:
    int dp[105][105][105][3];
    int solve(int x, int y, int z, int last) {
        if (x < 0 || y < 0 || z < 0) return -1e9;

        if (dp[x][y][z][last] != -1) return dp[x][y][z][last];

        int res = 0;
        if (last != 2)
        {
            res = max(res,solve(x,y-1,z,2)+2);
        }
        if (last != 1)
        {
            res = max(res,solve(x-1,y, z, 1)+2);
            res = max(res,solve(x, y, z-1, 2)+2);
        }
        dp[x][y][z][last] = res;
        return res;
    }

public:
    int longestString(int x, int y, int z) {
        memset(dp, -1, sizeof(dp));
        return solve(x, y, z, 0);
    }
};


int main()
{
    Solution s;
    cout << s.longestString(3, 2, 2) << endl;
    return 0;
}
