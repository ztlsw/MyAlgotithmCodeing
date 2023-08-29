#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;

class Solution {
public:
    map<int,int> mp;
    ll dp[1001];
    int numFactoredBinaryTrees(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0;i<len;i++)
        {
            dp[i] = 1;
            mp[arr[i]] = i;
        }
        for(int i = 0;i<len;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]%arr[j]==0)
                {
                    int tmp = arr[i]/arr[j];
                    if(mp.count(tmp))
                    {
                        dp[i] += dp[j]*dp[mp[tmp]];
                        dp[i]%=1000000007;
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0;i<len;i++)
        {
            ans+=dp[i];
            ans%=1000000007;
        }
        return ans;
    }
};



int main()
{
	Solution A;
    vector<int> arr = {2,4,5,10};
	cout<<A.numFactoredBinaryTrees(arr)<<endl;
	return 0;
}