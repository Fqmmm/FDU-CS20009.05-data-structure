#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTreeHelper(const string &preorder, int &preIndex, const string &inorder, int inStart, int inEnd, unordered_map<char, int> &inMap)
{
    if (preIndex >= preorder.length() || inStart > inEnd)
    {
        return nullptr;
    }

    char rootVal = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootVal);

    int inIndex = inMap[rootVal];

    root->left = buildTreeHelper(preorder, preIndex, inorder, inStart, inIndex - 1, inMap);
    root->right = buildTreeHelper(preorder, preIndex, inorder, inIndex + 1, inEnd, inMap);

    return root;
}

TreeNode *buildTree(const string &preorder, const string &inorder)
{
    if (preorder.empty() || inorder.empty())
    {
        return nullptr;
    }
    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.length(); ++i)
    {
        inMap[inorder[i]] = i;
    }
    int preIndex = 0;
    return buildTreeHelper(preorder, preIndex, inorder, 0, inorder.length() - 1, inMap);
}

bool findNode(TreeNode *root, char val)
{
    if (!root)
    {
        return false;
    }
    if (root->val == val)
    {
        return true;
    }
    return findNode(root->left, val) || findNode(root->right, val);
}

// 以root为根节点，寻找p和q的最低公共祖先
TreeNode *findLCA(TreeNode *root, char p, char q)
{
    if (!root || root->val == p || root->val == q)
    {
        return root;
    }

    TreeNode *left = findLCA(root->left, p, q);
    TreeNode *right = findLCA(root->right, p, q);

    if (left && right)
    {
        return root;
    }

    return left ? left : right;
}

int main()
{
    string inorder, preorder;
    char node1, node2;

    cin >> preorder >> inorder;
    cin >> node1 >> node2;

    TreeNode *root = buildTree(preorder, inorder);

    if (!findNode(root, node1) || !findNode(root, node2))
    {
        cout << "NA" << endl;
    }
    else
    {
        TreeNode *lca = findLCA(root, node1, node2);
        if (lca)
        {
            cout << lca->val << endl;
        }
        else
        {
            cout << "NA" << endl;
        }
    }

    return 0;
}
