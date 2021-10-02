#include <bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    int plats = 1;
    int maxPlats = 1;
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0;
    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            plats++;
            maxPlats = max(maxPlats, plats);
            i++;
        }
        else if (arr[i] > dep[j])
        {
            plats--;
            j++;
        }
    }
    // Your code here
    return maxPlats;
}