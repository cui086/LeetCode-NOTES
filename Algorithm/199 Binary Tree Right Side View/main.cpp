#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<int> rightSideView(TreeNode *root) 
    {
        vector<int> ans;
        if (root == NULL) 
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* curr;
        while(!que.empty()) 
        {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) 
            {
                curr = que.front(); que.pop();
                if (curr->left) 
                {
                    que.push(curr->left);
                }
                if (curr->right) 
                {
                    que.push(curr->right);
                }
            }
            ans.push_back(curr->val);
        }
        return ans;
    }
};

int main()
{
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->left->left = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(p);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}