#include <bits/stdc++.h>
#define ll long long
using namespace std;

void primeSieve(int *arr)
{
    // marking all the odd as primes...
    for (int i = 3; i < 1000000; i += 2)
    {
        arr[i] = 1;
    }

    // marking multiples of the numbers as non prime
    for (int i = 3; i < 1000000; i++)
    {
        if (arr[i] == 1)
        {
            for (ll j = i * i; j < 1000000; j += i)
            {
                arr[i] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[1] = arr[0] = 0;
}