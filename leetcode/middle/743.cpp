#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> v[n+10];
        for(int i=0;i<times.size();i++)
        {
            int fro=times[i][0];
            int too=times[i][1];
            int val=times[i][2];
            v[fro].push_back(make_pair(val,too));
        }
        int dis[101];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >que;

        memset(dis,0x3f3f3f,sizeof(dis));
        dis[k]=0;
        int maxx=0;
        que.push(make_pair(0,k));
        while(!que.empty())
        {
            pair<int,int> lim=que.top();
            que.pop();
            int now=lim.second;
            for(int i=0;i<v[now].size();i++)
            {
                pair<int,int> pii =v[now][i];
                if(dis[pii.second]>dis[now]+pii.first)
                {
                    dis[pii.second]=dis[now]+pii.first;
                    que.push(make_pair(dis[pii.second],pii.second));
                }
            }
        }
        for(int i=1;i<=n;i++) maxx=max(maxx,dis[i]);
        return (maxx>1e8) ? -1 : maxx;
    }
};