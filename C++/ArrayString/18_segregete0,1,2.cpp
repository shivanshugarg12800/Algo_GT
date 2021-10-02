#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums)
{
    int sum2 = 0, sum1 = 0;
    for (auto it : nums)
    {
        if (it == 2)
            sum2++;
        else if (it == 1)
            sum1++;
    }
    cout << sum2 << " " << sum1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (sum2 != 0)
        {
            nums[i] = 2;
            sum2--;
            continue;
        }
        if (sum2 == 0 and sum1 != 0)
        {
            nums[i] = 1;
            sum1--;
            continue;
        }
        if (sum2 == 0 and sum1 == 0)
        {
            nums[i] = 0;
        }
    }
}