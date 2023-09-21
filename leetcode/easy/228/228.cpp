#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string>ans;
        string lim;
        nums.push_back(INT_MIN+1);
        int l = nums[0],r = nums[0];
        for(int i = 1;i<nums.size();i++)
        {

            if(nums[i-1]!=nums[i]-1)
            {
                if(l == r) lim = to_string(l);
                else lim = to_string(l) + "->" + to_string(r);
                l = nums[i];
                r = l;
                ans.push_back(lim);
            }
            else r++;
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int>nums = {0,1,2,4,5,7};
    vector<string>ans = sol.summaryRanges(nums);
    return 0;
}