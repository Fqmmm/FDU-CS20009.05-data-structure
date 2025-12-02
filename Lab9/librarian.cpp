#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int id; // 书籍编号
    TreeNode *left;
    TreeNode *right;

    TreeNode(int i, TreeNode *l, TreeNode *r)
    {
        this->id = i;
        this->left = l;
        this->right = r;
    }
};

class Tree
{
public:
    Tree() : root(nullptr) {}
    int search(int i);
    void buildTree(vector<int> arr);
private:
    TreeNode *root;
    TreeNode* insert(TreeNode *root, int i, bool & success, int & depth);  // 插入并返回层数信息
};

// 插入节点，success表示是否成功插入（不重复）
TreeNode* Tree::insert(TreeNode *node, int i, bool & success, int & depth)
{
    if (node == nullptr)
    {
        success = true;
        return new TreeNode(i, nullptr, nullptr);
    }
    
    if (i == node->id)
    {
        success = false;
        return node;
    }
    else if (i < node->id)
    {
        node->left = insert(node->left, i, success, depth);
        if (success) depth++;
    }
    else
    {
        node->right = insert(node->right, i, success, depth);
        if (success) depth++;
    }
    
    return node;
}

void Tree::buildTree(vector<int> arr)
{
    if (arr.empty()) 
    {
        root = nullptr;
        return;
    }
    
    // 插入第一个节点
    root = new TreeNode(arr[0], nullptr, nullptr);
    
    // 插入剩余节点
    for (int i = 1; i < arr.size(); i++)
    {
        bool success = true;
        int depth = 1;  // 根节点为第1层
        insert(root, arr[i], success, depth);
        
        if (!success)
        {
            cout << "ERROR" << endl;
        }
    }
}

int Tree::search(int i)
{
    if (root == nullptr) return -1;
    
    TreeNode *current = root;
    int level = 1;  // 根节点为第1层
    
    while (current != nullptr)
    {
        if (i == current->id)
        {
            return level;
        }
        else if (i < current->id)
        {
            current = current->left;
            level++;
        }
        else
        {
            current = current->right;
            level++;
        }
    }
    
    return -1;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int x;
    cin >> x;
    
    // 特殊情况：n=0时树为空
    if (n == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    
    Tree tree;
    tree.buildTree(arr);
    
    int result = tree.search(x);
    cout << result << endl;
    
    return 0;
}