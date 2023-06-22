class Solution 
{
public:

    inline void dfs(vector<vector<int>>& land, vector<int>& vis, int i, int j, int& cnt)
    {
        int n = land.size();
        int m = land[0].size();
        if(i<0 || i>=n || j<0 || j>=m || land[i][j] != 0 || vis[i*m+j] == 1)
            return;
        vis[i*m+j] = 1;
        cnt++;
        dfs(land, vis, i+1, j, cnt);
        dfs(land, vis, i-1, j, cnt);
        dfs(land, vis, i, j+1, cnt);
        dfs(land, vis, i, j-1, cnt);
        dfs(land, vis, i+1, j+1, cnt);
        dfs(land, vis, i+1, j-1, cnt);
        dfs(land, vis, i-1, j+1, cnt);
        dfs(land, vis, i-1, j-1, cnt);
    }
    vector<int> pondSizes(vector<vector<int>>& land) 
    {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(land[i][j] == 0 && vis[i*m+j] == 0)
                {
                    int cnt = 0;
                    dfs(land, vis, i, j, cnt);
                    ans.push_back(cnt);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};