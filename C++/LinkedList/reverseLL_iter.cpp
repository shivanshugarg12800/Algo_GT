// in this we will reverse the given linked lists using the iterative approach
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data= data;
        next= NULL;
    }
};
node* takeinput()
{
    int data;
    cin>> data;
    node* head = NULL;
    node* tail = NULL;
    while(data!=-1)
    {
    node* newnode= new node(data);
    if(head== NULL)
    {
        head= newnode;
        tail= newnode;
    }
    else
    {
        tail->next= newnode;
        tail= newnode;
    }
    cin>> data;
    }
return head;  
}
node* reverseLL_iter(node* head)
{
    node* prev= NULL;
    node* curr= head;
    node* next = NULL;
    while(curr!=NULL)
    {
      next= curr->next;
      curr->next= prev;
      prev= curr;
      curr= next;
    }
    
return prev;
}
void printLL(node* head)
{
    if(head==NULL)
    return;
    while(head!=NULL){
        cout<< head->data<<" ";
        head= head->next;
    }
}
int main()
{
  cout<< " Enter the Linked list :"<< endl;
  node* head= takeinput();
  printLL(head);
  cout<<endl;
  node*head1= reverseLL_iter(head);
  cout<< "the reversed Linked list is :" << endl;
  printLL(head1);






}
