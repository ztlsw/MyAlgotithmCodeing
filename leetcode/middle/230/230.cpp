#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
#include<map>
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
    inline void dfs(TreeNode *root,int &k,int &ans)
    {
        if(root->left!=nullptr) dfs(root->left,k,ans);

        k--;
        if(k == 0) ans = root->val;
        
        if(root->right != nullptr) dfs(root->right,k,ans);

        return ;
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = 0;
        dfs(root,k,ans);
        return ans;
    }
};


int main()
{

    return 0;
}