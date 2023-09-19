#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > que;
        vector<vector<int>> ans;
        pair<int,int> pii,pii2;
        for(int i = 0;i<intervals.size();i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            que.push({x,y});
        }
        while(!que.empty())
        {
            pii = que.top();
            que.pop();
            if(que.empty())
            {
                ans.push_back({pii.first,pii.second});
                break;
            }
            else
            {
                pii2 = que.top();
                if(pii.second>=pii2.first)
                {
                    que.pop();
                    que.push({min(pii.first,pii2.first),max(pii2.second,pii.second)});
                }
                else 
                {
                    ans.push_back({pii.first,pii.second});
                }
            }
        }
        return ans;
    }
};