#define ll long long
class Solution {
public:
    inline bool chk(ll x,vector<int>& ranks,int c)
    {
        ll n = ranks.size();
        for(int i = 0;i<n;i++)
        {
            ll lim = sqrt(x/ranks[i]);
            c-=lim;
            if (c<=0) return 1;
        }
        return 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 0,r = 1e18+7;
        ll ans = 0;
        while(l<=r)
        {
            ll mid = (l+r)/2;
            if(chk(mid,ranks,cars)) {ans = mid;r = mid-1;}
            else l = mid+1;
        }
        return ans;
    }
};