#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<map>
#define pii pair<int,int>
using namespace std;


class Solution 
{
    public:
        vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
        {
            vector<vector<bool>> dp(numCourses,vector<bool>(numCourses,false));
            vector<vector<int>> mp(numCourses+1);
            vector<int> indeg(numCourses,0);
            for(int i = 0;i<prerequisites.size();i++)
            {
                dp[prerequisites[i][0]][prerequisites[i][1]]=true;
                mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
                indeg[prerequisites[i][1]]++;
            }
            for(int i = 0;i<numCourses;i++)
            {
                for(int j = 0;j<numCourses;j++)
                {
                    for(int k = 0;k<numCourses;k++)
                    {
                        if(dp[j][i]&&dp[i][k]) dp[j][k]=true;
                    }
                }
            }
            vector<bool> ans;
            for(int i = 0;i<queries.size();i++)
            {
                if(dp[queries[i][0]][queries[i][1]]) ans.push_back(true);
                else ans.push_back(false);
            }
            return ans;
        }
};


int main()
{
    Solution s;
    vector<vector<int>> v = {{1,0},{2,0}};
    vector<vector<int>> v1 = {{1,0},{1,2}};
    vector<vector<int>> v2 = {{1,0},{0,1}};
    vector<vector<int>> v3 = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> v4 = {{1,0},{2,0},{3,1},{3,2}};
    vector<vector<int>> v5 = {{1,0},{2,0},{3,1},{3,2},{0,3}};

    return 0;
}