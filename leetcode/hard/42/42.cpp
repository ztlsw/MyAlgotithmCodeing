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
        if(n <=2) return 0;
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
                now = left.top();
            }
            else
            {
                left.pop();
                if(left.empty()) left.push({height[i],1});
                else
                {
                    pair<int,int> now2 = left.top();
                    while(!left.empty())
                    {
                        //union with left now2
                        if(now2.first<height[i])
                        {
                            ans += (now2.first-now.first)*now.second;
                            now = {now2.first,now.second+now2.second};
                            left.pop();
                            if(left.empty())
                            {
                                left.push({height[i],1});
                                break;
                            }
                            now2 = left.top();
                            continue;
                        }
                        //union with right new
                        if(now2.first>height[i])
                        {
                            ans += (height[i]-now.first)*now.second;
                            left.push({height[i],now.second+1});
                            break;
                        }
                        //equal
                        if(now2.first == height[i])
                        {
                            ans += (height[i]-now.first)*now.second;
                            left.pop();
                            left.push({height[i],now.second+now2.second+1});
                            break;
                        }
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
    vector<int> b = {0};
    cout<<a.trap(b)<<endl;
    return 0;
}