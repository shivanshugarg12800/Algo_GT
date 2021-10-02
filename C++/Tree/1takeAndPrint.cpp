// in this we will be taking levelwise input from a tree and we'll also print it in levelwise order
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    // making tree node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> TreeQueue;

    // push root in the queue
    TreeQueue.push(root);

    // check in the loop
    while (TreeQueue.size() != 0)
    {
        TreeNode<int> *front = TreeQueue.front();
        TreeQueue.pop();

        // get the number of childs of the top node....
        cout << "Enter the number of children of" << front->data << endl;
        int numchild;
        cin >> numchild;

        // now run the loop number of child times and input the children's data
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "enter the " << i << "th child of " << front->data << endl;
            cin >> childData;
            // create the tree node of the child data
            TreeNode<int> *child = new TreeNode<int>(childData);
            // push it in the vector of the front node....
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
int main()
{
    TreeNode<int> *root = takeInput();
    PrintLevelWise(root);
}