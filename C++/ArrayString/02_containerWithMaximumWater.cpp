#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &arr)
{
    int n = arr.size();
    if (n == 2)
        return min(arr[0], arr[1]);
    int i = 0, j = n - 1;
    int maxArea = INT_MIN;
    while (i <= j)
    {
        if (arr[i] > arr[j])
        {
            int area = arr[j] * (j - i);
            maxArea = max(area, maxArea);
            j--;
        }
        else
        {
            int area = arr[i] * (j - i);
            maxArea = max(area, maxArea);
            i++;
        }
    }
    return maxArea;
}