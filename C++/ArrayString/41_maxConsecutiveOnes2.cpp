#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    // write your code here
    int maxLen = INT_MIN;
    int Zcount = 0, j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            Zcount++;
        while (Zcount > 1)
        {
            j++;
            if (nums[j] == 0)
                Zcount--;
        }
        int len = i - j;
        if (len > maxLen)
            maxLen = len;
    }
    return maxLen;
}