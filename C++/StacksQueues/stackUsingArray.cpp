// In this we will create stackk using the array
#include<iostream>
using namespace std;
class Stack{
private:
   int *data;
   int nextindex;
   int capacity;
public:
   Stack()
   {
      data= new int[4];
      nextindex= 0;
      capacity= 4;
   }
// this is the function for checking size of the stack:
   int size()
   {
    return nextindex;
   }

// this is the function to know if the stack is empty or not:
   bool isEmpty()
   {
    return nextindex==0;
   }

// this function is used for inserting the number in the stack
// we have made it using the dynamic array approach...
   void push(int element)
   {
    if(nextindex==capacity)
    {
      int *newdata= new int[2*capacity];
      for(int i=0; i<(2*capacity); i++)
      {
        newdata[i]=data[i];
      }
      delete []data;
      data = newdata;
    }
    data[nextindex]= element;
    nextindex++;
   }
// this function deletes the topmost element
   int pop()
  {
    nextindex--;
    return data[nextindex];
  }
// this function shows topmost
   int top()
  {
    return data[nextindex-1];
  }

};
int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<< s1.size()<<endl;
    cout<< s1.top()<<endl;
    cout<< s1.pop()<<endl;
    cout<< s1.top()<<endl;

}