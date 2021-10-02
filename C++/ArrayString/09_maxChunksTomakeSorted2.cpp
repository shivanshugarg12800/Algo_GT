#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();
    vector<int> maxE;
    vector<int> minE;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            maxE.push_back(arr[i]);
            continue;
        }
        maxE.push_back(max(maxE.back(), arr[i]));
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            minE.push_back(arr[i]);
            continue;
        }
        minE.push_back(min(minE.back(), arr[i]));
    }
    reverse(minE.begin(), minE.end());
    minE.push_back(INT_MAX);
    for (int i = 0; i < n; i++)
    {
        if (maxE[i] <= minE[i + 1])
            count++;
    }

    return count;
}