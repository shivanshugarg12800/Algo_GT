#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int temp = 1;
    bool zero = false;
    int zeroCount = 0;
    for (auto itr : nums)
    {
        if (itr != 0)
        {
            temp *= itr;
        }
        else
        {
            zero = true;
            zeroCount++;
        }
    }

    vector<int> final(nums.size(), temp);

    if (zeroCount == nums.size() || zeroCount >= 2)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            final[i] = 0;
        }
    }
    else
    {
        if (zero)
        {
            for (int i = 0; i < final.size(); i++)
            {
                if (nums[i] != 0)
                {
                    final[i] = 0;
                }
            }
        }
        else
        {
            for (int i = 0; i < final.size(); i++)
            {
                if (nums[i] != 0)
                {
                    final[i] = final[i] / nums[i];
                }
            }
        }
    }
    return final;
}