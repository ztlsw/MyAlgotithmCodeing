#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
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
    inline pair<int,int> dfs(TreeNode* root)
    {
        int ans0 = 0,ans1 = root->val;
        if(root->left != nullptr)
        {
            pair<int,int> pii = dfs(root->left);
            ans0 = max(pii.first,pii.second);
            ans1 += pii.first;
        }
        if(root->right != nullptr)
        {
            pair<int,int> pii = dfs(root->right);
            ans0 += max(pii.first,pii.second);
            ans1 += pii.first;
        }
        return {ans0,ans1};
    }
    int rob(TreeNode* root) 
    {
        pair<int,int> pii = dfs(root);
        return max(pii.first,pii.second);
    }
};
