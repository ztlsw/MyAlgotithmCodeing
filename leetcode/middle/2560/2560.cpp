#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
class Solution 
{
public:
    inline bool che(int x,vector<int>& nums,int k)
    {
        int tot = 0;
        for(auto num : nums)
        {
            if(num<=x) tot++;
            else
            {
                k-=(tot+1)/2;
                tot = 0;
            }
        }
        k-=(tot+1)/2;
        return (k<=0);
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int l = 0,r = 1e9+7;
        int mid,ans;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(che(mid,nums,k))
            {
                r = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};