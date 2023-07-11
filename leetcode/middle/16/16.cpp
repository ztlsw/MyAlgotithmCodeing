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
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int minn = 0x3f3f3f3f;
        int ans = 0;
        int len = nums.size();
        for(int i = 0;i < len ; i++)
        {
            for(int j = i + 1;j < len ; j++)
            {
                for(int k = j + 1;k < len ; k++)
                {
                    int limm = nums[i] + nums[j] + nums[k];
                    if(abs(limm - target) <= minn)
                    {
                        ans = limm;
                        minn = abs(limm - target);
                    }
                }
            }
        }
        return ans;
    }
};