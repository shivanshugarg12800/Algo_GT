// in this code we need to mirror the given generic tree
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> TreeQueue;
    TreeQueue.push(root);
    while (TreeQueue.size() != 0)
    {
        TreeNode<int> *front = TreeQueue.front();
        TreeQueue.pop();
        cout << "Enter the number of children of" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "enter the " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            TreeQueue.push(child);
        }
    }
    return root;
}
void PrintLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> tree;
    tree.push(root);
    while (tree.size() != 0)
    {
        TreeNode<int> *front = tree.front();
        tree.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            tree.push(front->children[i]);
        }
        cout << endl;
    }
}

void mirror(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    // lets assume the children of the root are already mirrors using the recursion
    for (auto node : root->children)
    {
        mirror(node);
    }
    // just reverse the children of the root...
    reverse(root->children.begin(), root->children.end());
}

int main()
{
    TreeNode<int> *root = takeInput();
    PrintLevelWise(root);
    mirror(root);
    PrintLevelWise(root);
}