#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int zcount = 0;
    int maxLen = 0;
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zcount++;

        while (zcount > k)
        {
            j++;
            if (nums[j] == 0)
                zcount--;
        }
        int len = i - j;
        if (len > maxLen)
            maxLen = len;
    }
    return maxLen;
}