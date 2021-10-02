#include <bits/stdc++.h>
using namespace std;

void binSort(int A[], int n)
{
    //Your code here
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (sum == 0)
        {
            A[i] = 0;
            continue;
        }
        else
            A[i] = 1;
        sum--;
    }

    /**************
        * No need to print the array
        * ************/
}