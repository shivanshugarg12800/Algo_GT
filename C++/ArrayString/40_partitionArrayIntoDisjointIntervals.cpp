#include <bits/stdc++.h>
using namespace std;

// intuition behind the approach
// we'll maintain a curr_max and globalMax for every element
// if curr_max is less than the nums[i], that means, we have begin to see the right part of the array in which every element is greater than the cur_max
// if curr_max becomes greater than the nums[i], this means we have to enlarge the size of the left part by making curr_max = global max
int partitionDisjoint(vector<int> &nums)
{
    int curr_max = nums[0];
    int maxE = curr_max;
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxE)
            maxE = nums[i];

        if (curr_max > nums[i])
        {
            curr_max = maxE;
            index = i;
        }
    }
    if (index + 1 == nums.size())
        return 1;

    return index + 1;
}