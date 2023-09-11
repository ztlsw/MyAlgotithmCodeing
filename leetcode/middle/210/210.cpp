#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> indeg(numCourses,0);
        vector<int> mp[numCourses+1],anss;
        queue<int> now_dedg_zero;
        for(int i = 0;i<prerequisites.size();i++)
        {
            int x = prerequisites[i][1];
            int y = prerequisites[i][0];
            indeg[y]++;
            mp[x].push_back(y);
        }
        int tot = 0;
        for(int i = 0;i<numCourses;i++)
        {
            if(indeg[i] == 0)
            {
                now_dedg_zero.push(i);tot++;
            }
        }
        while(!now_dedg_zero.empty())
        {
            int x = now_dedg_zero.front();
            now_dedg_zero.pop();
            anss.push_back(x);
            for(int i = 0;i<mp[x].size();i++)
            {
                int y = mp[x][i];
                indeg[y] --;
                if(indeg[y] == 0) {now_dedg_zero.push(y);tot++;}
            }
        }

        if(tot != numCourses) anss.clear();
        return anss;
    }
};

int main()
{

    return 0;
}