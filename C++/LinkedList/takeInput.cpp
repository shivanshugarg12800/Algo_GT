/* in this we will see two ways to take input in the linked lists 
 first is the iterative way to take input and second is the double node method where we use two nodes head and
 tail  to take input */

#include<iostream>
using namespace std;
class node{
 public :
    int Data;
    node *next;
 node(int data)
 {
     this->Data= data;
      next=NULL;
 }
};
node* takeInput_1()
{
    int data; 
    cin>> data;
     node* head= NULL;
     while(data!=-1)
     {
        node* newnode= new node(data);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
         node* temp= head;
        while(temp->next!=NULL)
         {
             temp= temp->next;
         }
         temp->next= newnode;
        }
         cin>> data;
         
     }
return head;
}

node* takeInput_2()
{
    int data;
    cin>> data;
    node* head= NULL;
    node* tail= NULL;
   
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
         tail->next=newnode;
         tail= newnode;
     }
     cin>> data; 
    }
    return head;
}
void printLL(node* head)
{
    while(head!=NULL)
    {
        cout<<head->Data<< " ";
        head=head->next;
    }
}
int main()
{
    node* head= takeInput_1();
    printLL(head);
    node* head1 = takeInput_2();
    printLL(head1);
}