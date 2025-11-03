#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getPostorder(const string &inorder, const string &preorder)
{

    if (inorder.empty())
    {
        return "";
    }

    char root_char = preorder[0];
    int idx = inorder.find(root_char);
    string left_inorder = inorder.substr(0, idx);
    string right_inorder = inorder.substr(idx + 1);
    string left_preorder = preorder.substr(1, left_inorder.length());
    string right_preorder = preorder.substr(1 + left_inorder.length());

    // 递归处理左右子树
    string left_postorder = getPostorder(left_inorder, left_preorder);
    string right_postorder = getPostorder(right_inorder, right_preorder);

    return left_postorder + right_postorder + root_char;
}

int main()
{
    string inorder_str, preorder_str;
    cin >> inorder_str >> preorder_str;
    cout << getPostorder(inorder_str, preorder_str) << endl;
    return 0;
}
