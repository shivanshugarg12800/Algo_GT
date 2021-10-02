// in this we will reverse the given linked lists using the recursive  approach
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
/* the reversal is like this 
  1 -> 2 -> 3 -> 4-> 5
  we will assumee the recursion gave us the reversed LL
   1 -> 2 <- 3 <- 4 <- 5  
*/
node* reverseLL_rec(node* head)
{
    if(head==NULL || head->next== NULL)
     return head;

    node* smallhead = reverseLL_rec(head->next);
    head->next->next= head;
    head->next= NULL;

return smallhead;
}
void printLL(node* head)
{
    if(head==NULL)
    return;
    while(head!=NULL)
    {
        cout<< head->data<< " ";
        head= head->next;
    }
}
int main()
{
    node* head=takeinput();
    printLL(head);
    cout<<endl;
    node* head1= reverseLL_rec(head);
    printLL(head1);
}