#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree
{
public:
    Node *root;
    Tree(Node *root)
    {
        this->root = root;
    }
    void preOrder();  // 前序遍历
    void inOrder();   // 中序遍历
    void postOrder(); // 后序遍历
    static Tree buildTree(); // 根据层序遍历序列构建树

private:
    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
};

void Tree::preOrder()
{
    preOrder(root);
}

void Tree::inOrder()
{
    inOrder(root);
}

void Tree::postOrder()
{
    postOrder(root);
}

void Tree::preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void Tree::postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

Tree Tree::buildTree()
{
    string val;

    cin >> val; // 直接从标准输入读取第一个值
    if (val == "null" || val.empty())
    {
        return Tree(nullptr); // 如果根节点为空，返回空树
    }

    Node *rootNode = new Node(stoi(val), nullptr, nullptr);
    queue<Node *> q; // 使用队列来辅助层序构建
    q.push(rootNode);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        // 读取并构建左子节点
        if (!(cin >> val))
        {
            break; 
        }
        if (val != "null")
        {
            Node *leftChild = new Node(stoi(val), nullptr, nullptr);
            current->left = leftChild;
            q.push(leftChild);
        }

        // 读取并构建右子节点
        if (!(cin >> val))
        {
            break; 
        }
        if (val != "null")
        {
            Node *rightChild = new Node(stoi(val), nullptr, nullptr);
            current->right = rightChild;
            q.push(rightChild);
        }
    }
    return Tree(rootNode);
}

int main()
{
    // 直接通过静态方法构建树
    Tree myTree = Tree::buildTree();

    if (myTree.root != nullptr)
    {
        myTree.preOrder();
        cout << endl;
        myTree.inOrder();
        cout << endl;
        myTree.postOrder();
        cout << endl;
    }

    return 0;
}