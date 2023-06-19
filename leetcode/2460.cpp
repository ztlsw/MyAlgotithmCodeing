#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        multiset<string> srow, scol;
        for(int i = 0; i < n; i++)
        {
            string str = "";
            for(int j = 0; j < n; j++)
            {
                str += to_string(grid[i][j]);
                str += ",";
            }
            srow.insert(str);
        }
        for(int j = 0; j < n; j++)
        {
            string str = "";
            for(int i = 0; i < n; i++)
            {
                str += to_string(grid[i][j]);
                str += ",";
            }
            scol.insert(str);
        }
        int ans = 0;
        for(auto i:srow)
        {
            int cnt = 0;
            for(auto j:scol)
            {
                if(i == j)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};