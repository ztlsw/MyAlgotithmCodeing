#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
class Solution {
private:
    struct peop
    {
        int id;
        int time;
        peop(int id,int time):id(id),time(time){}
        bool operator > (const peop &a) const
        {
            if(time==a.time) return id<a.id;
            return time<a.time;
        }
    };
    struct acti
    {
        int id;
        /*四种状态：桥上左到右(0),桥上右到左(1),去左仓库(2)，去右仓库(3)*/
        int stat;
        /*结束时间*/
        int time;
        acti(int id,int stat,int time):id(id),stat(stat),time(time){}
        bool operator > (const acti &a) const
        {
            if(time==a.time) return id>a.id;
            return time>a.time;
        }
    };
    /*三优先队列，表示的是左边桥边的状态，右边桥边的状态，活状态()*/
    priority_queue<peop, vector<peop>,greater<peop> > LeftBridge,RigthBridge;
    priority_queue<acti, vector<acti>,greater<acti> > LiveActive;
public:
    inline void ycl(vector<vector<int>>& time)
    {
        for(int i=0;i<time.size();i++)
        {
            LeftBridge.push(peop(i,time[i][0]+time[i][2]));
        }
    }
    int findCrossingTime(int n, int k, vector<vector<int>>& time) 
    {
        //桥上状态
        bool brdge = 0;
        //派出的工人数
        int dont = 0;
        //目前时间
        int nowtime = 0;
        ycl(time);
        while(n)
        {
            if(!brdge)
            {
                if(!RigthBridge.empty())
                {
                    peop now = RigthBridge.top();
                    RigthBridge.pop();
                    int timelim = nowtime + time[now.id][2];
                    LiveActive.push(acti(now.id,1,timelim));
                    brdge=1;
                }
                else if(!LeftBridge.empty())
                {
                    if(n>dont)                     //桥没被占用，但是还需要工人
                    {
                        peop now = LeftBridge.top();
                        LeftBridge.pop();
                        int timelim = nowtime + time[now.id][0];
                        LiveActive.push(acti(now.id,0,timelim));
                        brdge=1;
                        dont++;
                    }
                }
            }
            while(!LiveActive.empty())
            {
                acti lim = LiveActive.top();
                LiveActive.pop();
                nowtime = lim.time;     //结束时间,让这项活事务结束
                switch(lim.stat)
                {
                    case 0:
                        LiveActive.push(acti(lim.id,3,nowtime+time[lim.id][1]));
                        brdge=0;
                        break;
                    case 1:
                        n--;
                        dont--;
                        LiveActive.push(acti(lim.id,2,nowtime+time[lim.id][3]));
                        brdge=0;
                        break;
                    case 2:
                        LeftBridge.push(peop(lim.id,time[lim.id][0]+time[lim.id][2]));
                        break;
                    case 3:
                        RigthBridge.push(peop(lim.id,time[lim.id][0]+time[lim.id][2]));
                        break;
                }
                if(!LiveActive.empty()&&LiveActive.top().time==nowtime) continue;
                else break;
            }
        }
        return nowtime;
    }
};


int main()
{
    Solution a;
    vector<vector<int>> time = {{1,9,1,8},{10,10,10,10}};
    cout<<a.findCrossingTime(3,2,time)<<endl;
    return  0;
}