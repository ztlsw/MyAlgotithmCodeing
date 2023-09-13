#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<cctype>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    inline int dfs(TreeNode *root,int &ans)
    {
        if(root == nullptr) return 0;
        int lmax = dfs(root->left,ans);
        int rmax = dfs(root->right,ans);
        int lim = max(root->val,max(lmax+root->val,rmax+root->val));
        lim = max(lim,lmax+rmax+root->val);
        ans = max(ans,lim);
        int maxx = max(lmax,rmax);
        return max(maxx + root->val,root->val);
    }
    int maxPathSum(TreeNode* root)
    {
        int ans = -1e9;
        dfs(root,ans);
        return ans;
    }
};