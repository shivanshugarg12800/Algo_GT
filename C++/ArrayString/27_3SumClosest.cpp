#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    if (nums.size() < 3)
        return 0;
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 or (i > 0 and nums[i] != nums[i - 1]))
        {
            int si = i + 1, ei = nums.size() - 1;
            while (si < ei)
            {
                int currDiff = abs(target - (nums[i] + nums[si] + nums[ei]));
                if (currDiff < diff)
                {
                    diff = currDiff;
                    ans = nums[i] + nums[si] + nums[ei];
                }
                else if (nums[i] + nums[si] + nums[ei] < target)
                    si++;
                else
                    ei--;
            }
        }
    }
    return ans;
}