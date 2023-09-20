#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    inline void dfs(vector<vector<char>>& board,vector<vector<bool>> &vis,int x,int y)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || vis[x][y] || board[x][y] == 'X') return;
        vis[x][y] = true;
        dfs(board,vis,x+1,y);
        dfs(board,vis,x-1,y);
        dfs(board,vis,x,y+1);
        dfs(board,vis,x,y-1);
    }
    void solve(vector<vector<char>>& board) 
    {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0;i<board.size();i++)
        {
            if(board[i][0] == 'O') dfs(board,vis,i,0);
            if(board[i][board[0].size()-1] == 'O') dfs(board,vis,i,board[0].size()-1);
        }
        for(int i = 0;i<board[0].size();i++)
        {
            if(board[0][i] == 'O') dfs(board,vis,0,i);
            if(board[board.size()-1][i] == 'O') dfs(board,vis,board.size()-1,i);
        }
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};


int main()
{

    return 0;
}