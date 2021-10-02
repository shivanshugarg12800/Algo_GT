// depth of root is 0 but height of root is 1

#include<iostream>
#include "TreeNode.h"

using namespace std;
TreeNode<int>* takeInput()
{
    int rootData;
    cin>> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> TreeQueue;
    TreeQueue.push(root);
    while(TreeQueue.size()!=0)
    {
        TreeNode<int>* front = TreeQueue.front();
        TreeQueue.pop();
        cout<< "Enter the number of children of"<< front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++)
        {
            int childData;
            cout<<"enter the "<< i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            TreeQueue.push(child);
        }
    }
    return root;
}void PrintLevelWise(TreeNode<int>* root)
{
     if(root==NULL)
    {
        return ;
    }
    queue<TreeNode<int>*> tree;
    tree.push(root);
    while(tree.size()!=0)
    {
        TreeNode<int>* front = tree.front();
        tree.pop();
        cout<< front->data<< ":";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<",";
            tree.push(front->children[i]);
        }
        cout<<endl;
    }
}


int height(TreeNode<int>* root)
{
  int ans=0, temp=0 ;
    
  for(int i=0; i<root->children.size();i++)
  {
    temp= height(root->children[i]);
    if(temp>ans)
    {
        ans=temp;
    }  
      
  }
  return ans+1;
}
// this function is used to print the node at depth K

 void printAtLevelK(TreeNode<int>* root,int k)
 {
     if(root==nullptr){
         return;
     }
     if(k==0){
         cout<< root->data<<" ";
         return;
     }
     for(int i=0;i<root->children.size();i++)
     {
         printAtLevelK(root->children[i], k-1);
     }
 }
// this is the function used to replace all the treenode values with their depth values
  void printTreeWithDepthValue(TreeNode<int>* root, int depth){
      if(root==NULL)
      return;
    root->data=depth;
    for(int i=0;i<root->children.size();i++)
    {
        printTreeWithDepthValue(root->children[i], depth+1);
    }   
 }

int main()
{
    TreeNode<int>* root= takeInput();
    PrintLevelWise(root);
    cout<< height(root)<<endl;
    printAtLevelK(root, 1);
    PrintLevelWise(root);


}    