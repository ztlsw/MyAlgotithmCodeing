class Solution 
{
public:
    inline int dfs(vector<vector<int>> &vis,vector<vector<int>>& land,int n,int m,int i,int j)
    {
        int cnt = 1;
        if((i<0||j>=m||j<0||i>=n)||(!jud(vis[i][j],land[i][j]))) return 0;
        vis[i][j] = 1;
        cnt +=dfs(vis,land,n,m,i-1,j);
        cnt +=dfs(vis,land,n,m,i,j+1);
        cnt +=dfs(vis,land,n,m,i,j-1);
        cnt +=dfs(vis,land,n,m,i+1,j);
        cnt +=dfs(vis,land,n,m,i+1,j+1);
        cnt +=dfs(vis,land,n,m,i+1,j-1);
        cnt +=dfs(vis,land,n,m,i-1,j+1);
        cnt +=dfs(vis,land,n,m,i-1,j-1);
        return cnt;
    }
    vector<int> pondSizes(vector<vector<int>>& land) 
    {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(jud(vis[i][j],land[i][j]))
                {
                    int lim = dfs(vis,land,n,m,i,j);
                    ans.push_back(lim);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    inline bool jud(int a,int b)
    {
        if(a==0&&b == 0) return 1; 
        return 0;
    }
};