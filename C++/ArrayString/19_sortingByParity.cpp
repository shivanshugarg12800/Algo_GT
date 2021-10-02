#include <bits/stdc++.h>
using namespace std;
vector<int> sortArrayByParity(vector<int> &nums)
{
    int n = nums.size();
    for (auto it : nums)
        if (it % 2 == 0)
            nums.push_back(it);
    for (auto it : nums)
        if (it % 2 == 1)
            nums.push_back(it);
}