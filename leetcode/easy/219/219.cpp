#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        map<int,int> mp;
        queue<int>que;
        if(k == 0) return 0;
        int len = nums.size();
        for(int i = 0;i<len;i++)
        {
            if(mp[nums[i]] == 1) return 1;
            if(que.size()==k)
            {
                int lim = que.front();
                que.pop();
                mp[lim] = 0;
            }
            mp[nums[i]] = 1;
            que.push(nums[i]);
        }
        return 0;
    }
};


int main()
{

    return 0;
}