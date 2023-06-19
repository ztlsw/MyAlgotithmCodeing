#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    inline void dfs(int x,int y,int base,vector<vector<int>>& grid,int n,int m,int ask)
    {
        if(grid[x][y] == ask) grid[x][y] = base;
        if(x!=0&&grid[x-1][y] == 0) dfs(x-1,y,base,grid,n,m,ask);
        if(x!=n-1&&grid[x+1][y] == 0) dfs(x+1,y,base,grid,n,m,ask);
        if(y!=0&&grid[x][y-1] == 0) dfs(x,y-1,base,grid,n,m,ask);
        if(y!=m-1&&grid[x][y+1] == 0) dfs(x,y+1,base,grid,n,m,ask);
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int maxx = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    dfs(i,j,++maxx,grid,n,m,0);
                }
            }
        }
        vector<int> vis(maxx+1,0);
        for(int i = 0;i<n;i++)
        {
            if(grid[i][m-1] > 1 &&vis[grid[i][m-1]] == 0)
            {
                vis[grid[i][m-1]] = 1;
                maxx--;
            }
            if(grid[i][0] > 1 &&vis[grid[i][0]] == 0)
            {
                vis[grid[i][0]] = 1;
                maxx--;
            }
        }
        
        for(int j = 0;j<m;j++)
        {
            if(grid[n-1][j] > 1 &&vis[grid[n-1][j]] == 0)
            {
                vis[grid[n-1][j]] = 1;
                maxx--;
            }
            if(grid[0][j] > 1 &&vis[grid[0][j]] == 0)
            {
                vis[grid[0][j]] = 1;
                maxx--;
            }
        }
            
        return maxx-1;
    }
};
