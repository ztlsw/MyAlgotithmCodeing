class Solution 
{
    public:
        int giveGem(vector<int>& gem, vector<vector<int>>& operations) 
        {
            for(int i = 0;i<operations.size();i++)
            {
                int a = operations[i][0];
                int b = operations[i][1];
                gem[b] += gem[a]/2;
                gem[a]-=gem[a]/2;
            }
            int maxx = -1e9+7,minn = 1e9+7;
            for(int i = 0;i<gem.size();i++)
            {
                maxx = max(maxx,gem[i]);
                minn = min(minn,gem[i]);
            }
            return maxx - minn ;
        }
};