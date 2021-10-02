// given array ... we neeed to return the pair which sum to 0
#include<iostream>
#include<unordered_map>
using namespace std;

void pairSum(int *a, int size)
{
    unordered_map<int, int> seen;
    for(int i=0; i<size; i++)
    {
        seen[a[i]]=seen[a[i]]+1;
    }
    for(int i=0;i<size;i++)
    {
         if(seen[-a[i]]>0)
        {
            for(int j=0; j<seen[-a[i]];i++)
            {
                cout<< min(-a[i], a[i]) << max(-a[i], a[i])<<" ";
            }
            seen[a[i]]--;
        }

    }
  return;
}
int main()
{
    int a[]={1,2,3,-1,-2,-3,3,3};
    int size=8;
    pairSum(a,size);
}