#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
using namespace std;


class Solution 
{
public:
    queue<pair<int,int>> que;
    inline int bfs(vector<string>& chessboard,int n,int m)
    {
        auto vis=chessboard;
        int maxx = 0;
        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int a = -1;a<=1;a++)
            {
                for(int b = -1;b<=1;b++)
                {
                    if(a == 0&&b == 0) continue;
                    int xx = x+a;
                    int yy = y+b;
                    while(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy] == 'O')
                    {
                        xx+=a;
                        yy+=b;
                    }
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy] == 'X')
                    {
                        maxx += max(abs(xx-x-a),abs(yy-y-b));
                        xx-=a;
                        yy-=b;
                        while(xx!=x||yy!=y)
                        {
                            vis[xx][yy] = 'X';
                            que.push(make_pair(xx,yy));
                            xx-=a;
                            yy-=b;
                        }
                    }
                }
            }
        }
        return maxx;
    }
    int flipChess(vector<string>& chessboard) 
    {
        int maxx = -1;
        int n = chessboard.size();
        int m = chessboard[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(chessboard[i][j] == '.')
                {
                    que.push(make_pair(i,j));
                    maxx = max(maxx,bfs(chessboard,n,m));
                }
            }
        }
          
        return maxx;
    }
};

