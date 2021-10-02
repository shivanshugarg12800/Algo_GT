#include<iostream>
using namespace std;
template<typename T>
class node{
public:
    T data;
    node* next;

    node( T data)
   {
    this->data=data;
    next=NULL;
   }
};
template<typename T>
class Stack{
private:
  node<T> *head;
  int size;
  public:
  Stack()
  {
      head=NULL;
       size=0;
  }
   void Push(T element)
   {
       node<T> *newnode= new node<T>(element);
       if(head==NULL)
       {
           head= newnode;
       }
       else
       {
         newnode->next= head;
         head=newnode;   
       }
      size++; 
   }
   int getsize()
   {
       if(head==NULL)
       {
           return 0;
       }

      return size; 
   }
 bool isEmpty()
 {
   return size==0;  
 }
 T top()
 {
     if(head==NULL)
       {
           return 0;
       }
      return head->data; 
     
 }
T pop()
{
    if(head==NULL)
       {
           cout<< "Stack is Empty"<<endl;
           return 0;
       }
       T ans= head->data;
       head= head->next;
       size--;

       return ans;
}

};
int main()
{
    Stack <int>S;
    S.Push(10);
    S.Push(20);
    S.Push(30);
    S.Push(40);
    S.Push(50);
    S.Push(60);
    S.Push(70);
    S.Push(80);
    S.Push(90);
    cout<< S.getsize()<<endl;
    cout<< S.top()<<endl;
    cout<< S.pop()<<endl;
    cout<< S.pop()<<endl;
    cout<< S.pop()<<endl;
    cout<< S.top()<<endl;
    cout<< S.getsize()<<endl;


}