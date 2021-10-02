// this is the Memoisation approach of Fibonacci

#include<iostream>
using namespace std;

int fibo2(int n)
{
    if(n<=1)
    {
        return n;
    }
    int *arr= new int[n+1];
    for(int i=0; i<n+1;i++)
    {
        arr[i]=-1;
    }
   if(arr[n]!=-1)
   {
     return arr[n];
   }
  
  int a = fibo2(n-1);
   int b= fibo2(n-2);
   arr[n]=a+b;

   return arr[n];
}
int main()
{
    int n;
    cin>>n;
    cout<< fibo2(n);
}