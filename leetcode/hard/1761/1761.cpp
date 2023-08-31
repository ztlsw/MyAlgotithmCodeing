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
        int deg[401];
        bool mp[401][401];
        int minTrioDegree(int n, vector<vector<int>>& edges) 
        {
            int ans = 1e9+7;
            vector<int> vec;
            memset(deg,0,sizeof(deg));
            int len = edges.size();
            for(int i = 0;i<len;i++)
            {
                deg[edges[i][0]]++;
                deg[edges[i][1]]++;
                mp[edges[i][0]][edges[i][1]] = 1;
                mp[edges[i][1]][edges[i][0]] = 1;
            }

            for(int i = 0;i<len;i++)
            {
                int l = edges[i][0];
                int r = edges[i][1];
                for(int j = 1;j<=n;j++)
                {
                    if(j==l||j==r) continue;
                    if(mp[l][j]&&mp[r][j])
                    {
                        ans = min(ans,deg[l]+deg[r]+deg[j]-6);
                    }
                }
            }
            if(ans==1e9+7) return -1;
            return ans;
        }
};


int main()
{
    Solution A;
    vector<vector<int>> vec = {{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    cout<<A.minTrioDegree(6,vec)<<endl;
    return 0;
}