#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;

    // we are going to split the problem into the two sum problem
    // for each element nums[i], we'll check if have two elements with sum ==- nums[i]

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 or (i > 0 and nums[i] != nums[i - 1]))
        {
            int si = i + 1, ei = nums.size() - 1, sum = 0 - nums[i];
            while (si < ei)
            {
                if (nums[si] + nums[ei] == sum)
                {
                    ans.push_back({nums[i], nums[si], nums[ei]});

                    // to handle the duplicate stuff
                    while (si < ei and nums[si] == nums[si + 1])
                        si++;
                    while (ei > si and nums[ei] == nums[ei - 1])
                        ei--;
                    si++, ei--;
                }
                else if (nums[si] + nums[ei] < sum)
                    si++;
                else
                    ei--;
            }
        }
    }
    return ans;
}