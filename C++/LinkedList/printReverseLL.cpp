// in this we will print the reversed LL
#include<iostream>
using namespace std;
class node{
public:
  int data;
  node* next;

  node(int data)
  {
      this->data=data;
      next= NULL;
  }
};

node* takeinput()
{
    int data;
    cin>> data;
    node* head = NULL;
    node* tail =NULL;
    while(data!=-1)
    {
     node* newnode= new node(data);
     if(head==NULL)
    {
        head= newnode;
        tail = newnode;
    }
    else
    {
        tail->next= newnode;
        tail = newnode;
    }
    cin>> data;
    }
    return head;
}
 void print(node* head)
{
    if(head==NULL)
    return;
    while(head!=NULL)
    {
        cout<< head->data<< " ";
        head= head->next;
    }
}
void printReverseLL(node* head)
{
    if(head==NULL)
    return;
    printReverseLL(head->next);
    cout<< head-> data<< " ";
}
int main()
{
  node* head= takeinput();
  print(head);
  cout<< endl;
  printReverseLL(head);

}