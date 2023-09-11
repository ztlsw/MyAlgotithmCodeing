#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#define pii pair<int,int>
using namespace std;


class Solution 
{
    public:
        int scheduleCourse(vector<vector<int>>& courses) 
        {
            priority_queue<pii,vector<pii>,greater<pii> >pq,pq2;
            priority_queue<pii,vector<pii>,less<pii> >pq1;
            int nowtime = 0;
            for(int i=0;i<courses.size();i++)
                pq.push(make_pair(courses[i][1],courses[i][0]));
            while(!pq.empty())
            {
                pii now = pq.top();
                pq.pop();
                pq1.push({now.second,now.first});
                nowtime+=now.second;
                if(nowtime>now.first)
                {
                    auto lim = pq1.top();
                    nowtime-=lim.first;
                    pq1.pop();
                }
            }
            return pq1.size();
        }
};


int main()
{
    Solution s;
    vector<vector<int>> v = {{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
    vector<vector<int>> v1 = {{100,200},{200,1300},{1000,1250},{2000,3200}};
    vector<vector<int>> v2 = {{1,2}};
    vector<vector<int>> v3 = {{7,16},{2,3},{3,12},{3,14},{10,19},{10,16},{6,8},{6,11},{3,13},{6,16}};
    cout<<s.scheduleCourse(v)<<endl;
    cout<<s.scheduleCourse(v1)<<endl;
    cout<<s.scheduleCourse(v2)<<endl;
    cout<<s.scheduleCourse(v3)<<endl;
    return 0;
}