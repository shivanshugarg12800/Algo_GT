// this is the Dynamic programming approach..
// to understsnd the Dynamic Programming approach we need to implement the code first with recursion
// then with the memoisation 

#include<iostream>
using namespace std;

int fibo3(int n)
{
  
   int *arr=new int[n+1];
   arr[0]=0;
   arr[1]=1;
   for(int i=2; i< n+1; i++)
   {
       arr[i]=arr[i-1]+arr[i-2];
   }
   return arr[n];
}
int main()
{
    int n;
    cin>>n;
    cout<< fibo3(n);
}