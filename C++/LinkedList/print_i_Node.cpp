/*in this we will print the i-th node of the linked list*/
#include<iostream>
using namespace std;
class node{
   
   public:
   int data;
   node* next;
   node(int data)
   {
       this ->data= data;
       next=NULL;
   }
};

node* takeinput()
{
  int data;
  cin>> data;
  node* head = NULL;
  node* tail= NULL;
  while(data!=-1)
  {
      node* newnode= new node(data);
      if(head==NULL)
      {
          head= newnode;
          tail= newnode;
      }
      else{
          tail->next= newnode;
          tail=newnode;
      }
      cin>> data;
  }
 return head;
}
 void Print_i_node(node* head, int num)
 {
     node* temp1= head;
     int count=0;
     while(temp1!=NULL)
     {
         temp1 = temp1->next;
         count++;
     }
     if(num>=count)
     return;

     node* temp2= head;
     for(int i=0; i<num; i++)
     {
         temp2= temp2->next;
     }
     cout<<temp2->data;
 }
 int main()
 {
     int num;
     node* head = takeinput();
     cout<< " enter the node to find:"<< endl;
     cin>>num;
     Print_i_node(head, num);
 }