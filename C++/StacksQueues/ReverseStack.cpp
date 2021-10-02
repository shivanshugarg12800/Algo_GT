// we are given a two stacks one contains integer and the other one is empty...
// we need to reverse the given stack only
#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &input1, stack<int> &input2)
{
    if(input1.empty())
    {
        return;
    }

   int x= input1.top();
   reverseStack(input1, input2);
   while(!input1.empty())
   {
       int b=input1.top();
         input1.pop();
         input2.push(b);
   }
   input2.push(x);
   while(!input2.empty())
   {
       int a= input2.top();
       input2.pop();
       input1.push(a);
   }
}
int main()
{
    stack<int> s1;
    stack<int> s2;
    int n;
    cout<< "Enter the number of elements in stack:"<<endl;
    cin>>n;
    int val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        s1.push(val);
    }
    while(!s1.empty())
    {
        cout<< s1.top()<<endl;
        s1.pop();
    }
    reverseStack(s1, s2);
    while(!s1.empty())
    {
        cout<< s1.top()<<endl;
        s1.pop();
    }
return 0;
}
