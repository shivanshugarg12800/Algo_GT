// we have to linearise the tree, that means each node should have only one child....
// linearise the tree in preorder fashion
/*    eg.
         1
       /  |  \
      2   3   4
    / \  / \   \
   5  6 7   8   9

 ans->   1-2-5-6-3-7-8-4-9
*/

#include <iostream>
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

TreeNode<int> *getTail(TreeNode<int> *node)
{
    while (node->children.size() == 1)
    {
        node = node->children[0];
    }
    return node;
}

// this approach is to use the recursion which returns the tree in such a way that
void LineariseRoot(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        LineariseRoot(root->children[i]);
    }
    // now we have to attach the last child of the root to the tail of the second last child
    // and so on
    while (root->children.size() > 1)
    {
        // getting the last child
        TreeNode<int> *LastNode = root->children[root->children.size() - 1];
        // and popping it
        root->children.pop_back();
        // getting the second last child which is basically on the last position now
        TreeNode<int> *SecondLastNode = root->children[root->children.size() - 1];
        // get the tail of the second last node to which we will attach the last node
        TreeNode<int> *tail = getTail(SecondLastNode);
        tail->children.push_back(LastNode);
    }

    int main()
    {
        TreeNode<int> *root = takeInput();
        PrintLevelWise(root);
        LineariseRoot(root);
        PrintLevelWise(root);
    }