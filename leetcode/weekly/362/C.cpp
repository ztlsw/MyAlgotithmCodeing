#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) 
    {
        vector<vector<int>>mv = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>ans = {{1,1,1},{1,1,1},{1,1,1}};
        map<vector<vector<int>>,bool> mp;
        queue<pair<vector<vector<int>>,int>> que;
        vector<vector<int>> lim2;
        vector<vector<int>> lim;
        int n = grid.size();
        que.push({grid,0});
        mp[grid] = true;
        int anss = 0;
        while(!que.empty())
        {
            auto li = que.front();
            lim = li.first;
            if(lim == ans) {anss = li.second;break;}
            que.pop();
            for(int i = 0;i<3;i++)
            {
                for(int j = 0;j<3;j++)
                {
                    if(lim[i][j] > 1)
                    {
                        lim[i][j]-=1;
                        for(int l = 0;l<4;l++)
                        {
                            int x = i+mv[l][0];
                            int y = j+mv[l][1];
                            if(x>=0&&x<3&&y>=0&&y<3)
                            {
                                lim2 = lim;
                                lim2[x][y] += 1;
                                if(mp.count(lim2)==0)
                                {
                                    mp[lim2] = true;
                                    que.push({lim2,li.second+1});
                                }
                            }
                        }
                    }
                }
            }
        }
        return anss;
    }
};

int main()
{
    Solution A;
    vector<vector<int>> grid = {{9,0,0},{0,0,0},{0,0,0}};
    cout<<A.minimumMoves(grid)<<endl;
    return 0;
}