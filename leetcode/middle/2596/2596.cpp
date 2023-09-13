#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;


class Solution 
{
    public:
        inline bool ck(int a,int b,int n,int m)
        {
            if(a<0||b<0||a>n||b>m) return 0;
            return 1;
        }
        bool checkValidGrid(vector<vector<int>>& grid) 
        {
            int nowx = 0,nowy = 0;
            int mv[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
            int nownum = -1;
            if(grid[0][0] == 0) nownum = 0;
            int n = grid.size();
            int m = grid[0].size();
            bool flag = 0;
            while(nownum<n*m-1)
            {
                flag = 0;
                for(int i = 0;i<8;i++)
                {
                    int orx = nowx;
                    int ory = nowy;
                    nowx +=mv[i][0];
                    nowy +=mv[i][1];
                    if(!ck(nowx,nowy,n-1,m-1))
                    {
                        nowx = orx;
                        nowy = ory;
                        continue;
                    }
                    cout<<grid[nowx][nowy]<<endl;
                    if(grid[nowx][nowy] == nownum+1)
                    {
                        nownum++;
                        flag = 1;
                        break;
                    }
                    nowy = ory;
                    nowx = orx;
                }
                if(!flag) return 0;
            }
            return 1;
        }
};