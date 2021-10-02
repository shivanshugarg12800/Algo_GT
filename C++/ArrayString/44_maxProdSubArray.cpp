#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    int maxProd = 0;
    int currProd = 1;
    for (int i = 0; i < n; i++)
    {
        currProd *= nums[i];
        maxProd = max(maxProd, currProd);
        if (currProd == 0)
            currProd = 1;
    }
    currProd = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        currProd *= nums[i];
        maxProd = max(maxProd, currProd);
        if (currProd == 0)
            currProd = 1;
    }
    return maxProd;
}