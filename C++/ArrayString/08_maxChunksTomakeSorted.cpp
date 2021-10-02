#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 1;
    if (n == 2)
    {
        if (arr[0] > arr[1])
            return 1;
        else
            return 2;
    }
    int count = 0;
    int i = 0;
    int maxIndex = 0;
    while (i < n)
    {
        maxIndex = max(arr[i], maxIndex);
        if (maxIndex == i)
            count++;
        i++;
    }
    return count;
}