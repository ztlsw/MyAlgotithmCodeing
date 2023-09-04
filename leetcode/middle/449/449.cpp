#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string lim = "";
        if(root == NULL)
        {
            return lim;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp == NULL)
            {
                lim += "-1,";
            }
            else
            {
                lim += to_string(tmp->val) + ",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return lim;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        TreeNode* root = NULL;
        if(data == "")
        {
            return root;
        }
        vector<string> v;
        for(int i = 0; i < data.size(); i++)
        {
            string tmp = "";
            while(data[i] != ',')
            {
                tmp += data[i];
                i++;
            }
            v.push_back(tmp);
        }
        queue<TreeNode*> q;
        root = new TreeNode(stoi(v[0]));
        TreeNode *tmp = root;
        q.push(root);
        for(int i = 1;i<v.size();i+=2)
        {
            while(q.front()==nullptr)    q.pop();
            string lim = v[i];
            string lim2 = v[i+1];
            if(v[i]!= "-1")
            {
                tmp = q.front();
                tmp->left = new TreeNode(stoi(lim));
                q.push(tmp->left);
            }
            else
            {
                q.push(NULL);
            }
            if(v[i+1] != "-1")
            {
                tmp = q.front();
                tmp->right = new TreeNode(stoi(lim2));
                q.push(tmp->right);
            }
            else
            {
                q.push(NULL);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;