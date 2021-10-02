#include<iostream>
#include<queue>
using namespace std;

void reverseQueue( queue<int> &input)
{
    if(input.empty())
    {
        return ;
    }
    int x= input.front();
    input.pop();
    reverseQueue(input);
    input.push(x);
}

int main()
{
    queue<int > input;
    int n;
    cout<< "enter the size of the queue:"<<endl;
    cin>>n;
    int val;
    for(int i=0; i<n;i++)
    {
        cin>> val;
        input.push(val);
    }
    reverseQueue(input);
    for(int i=0; i<n;i++)
    {
        cout<< input.front()<< " ";
        input.pop();
    }
}