// we need to print the intersection of given two arrays
#include<iostream>
#include<unordered_map>
using namespace std;

void printInteresection(int *input1, int m, int *input2,int n)
{
    unordered_map<int,int> seen;
    for(int i=0;i< m; i++)
    {
      seen[input1[i]]++;
    }
    for(int i=0; i< n; i++)
    {
        if(seen[input2[i]]>0)
        {
            cout<< input2[i]<<" ";
            seen[input2[i]]--;
        }
        
    }
}
int main()
{
    int m, n;
    cin>>m >>n;
    int *input1= new int[m];
    for(int i=0; i< m; i++)
    {
        cin>>input1[i];
    }
    int *input2= new int[n];
    for(int i=0; i< n; i++)
    {
        cin>>input2[i];
    }
    printInteresection(input1, m, input2, n);
}