#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode 
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator 
{
private:
    stack<TreeNode*> sta;
public:
    BSTIterator(TreeNode *root) 
    {
        while(!sta.empty())
            sta.pop();
        while(root) 
        {
            sta.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode *tmp=sta.top();
        sta.pop();
        int ret = tmp->val;
        tmp = tmp->right;
        while(tmp) 
        {
            sta.push(tmp);
            tmp = tmp->left;
        }
        return ret;
    }
};

int main()
{
    return 0;
}