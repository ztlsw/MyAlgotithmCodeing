#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
#include<map>
#define pii pair<int,int>
using namespace std;
class Solution {
public:
    inline bool chk(int x,int y)
    {
        if(x<0||x>=8||y<0||y>=8) return 0;
        return 1;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
    {
        vector<vector<int>> ans;
        map<pii,int> mp;
        for(int i = 0;i<queens.size();i++)
        {
            mp[{queens[i][0],queens[i][1]}] = 1;
        }
        int base[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        int x = king[0];
        int y = king[1];
        for(int i = 0;i<8;i++)
        {
            int kx = x,ky = y;
            while(chk(kx,ky))
            {
                if(mp.count({kx,ky}))
                {
                    ans.push_back({kx,ky});
                    break;
                }
                kx+=base[i][0];
                ky+=base[i][1];
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}