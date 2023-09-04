#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
class Solution 
{
public:
    stack <pair<int,int>> left;
    int trap(vector<int>& height) 
    {
        int st = 0;
        int n = height.size();
        while(height[st+1]>=height[st]) st++;   //找到第一个下降的位置
        left.push({height[st],1});
        int ans = 0;
        for(int i = st;i<n;i++)
        {
            pair<int,int> now = left.top();
            if(height[i]<now.first) left.push({height[i],1});
            else if(height[i] == now.first)
            {
                left.pop();
                left.push({height[i],now.second+1});
            }
            else
            {
                left.pop();
                if(left.empty()) left.push({height[i],1});
                else
                {
                    pair<int,int> now2 = left.top();
                    while(!left.empty()&&now2.first<=height[i])
                    {
                        ans += (height[i]-now2.first)*now.second;
                        now = {now2.first,now.second+now2.second};
                        left.pop();
                        if(left.empty()) break;
                        now2 = left.top();
                    }
                    if(left.empty())
                    { 
                        left.push({height[i],1});
                    }
                    else
                    {
                        ans += (height[i]-now.first)*now.second;
                        left.push({height[i],now.second+1});
                    }
                }

            }
        }
        return ans;
    }
};


int main()
{
    Solution a;
    vector<int> b = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<a.trap(b)<<endl;
    return 0;
}