#include <bits/stdc++.h>
using namespace std;
int subarrayWithMaxElement(vector<int> &nums, int k)
{
    int n = nums.size();
    int s = 0;
    int i = 0;
    while (i < n)
    {
        if (nums[i] > k)
        {
            i++;
            continue;
        }

        int count = 0;
        while (i < n and nums[i] <= k)
        {
            i++;
            count++;
        }
        s += (count * (count + 1)) / 2;
    }
    return s;
}

int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
{
    if (nums.size() <= 0)
        return 0;

    return subarrayWithMaxElement(nums, right) - subarrayWithMaxElement(nums, left - 1);
}