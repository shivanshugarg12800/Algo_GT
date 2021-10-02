#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int cnt1 = 0, cnt2 = 0;
    int f = 0, s = 0;
    for (auto it : nums)
    {
        if (f == it)
            cnt1++;
        else if (s == it)
            cnt2++;
        else if (cnt1 == 0)
        {
            f = it;
            cnt1++;
        }
        else if (cnt2 == 0)
        {
            s = it;
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cout << f << " " << s << endl;
    cnt1 = 0, cnt2 = 0;
    for (auto it : nums)
        if (it == f)
            cnt1++;
        else if (it == s)
            cnt2++;
    vector<int> ans;
    if (cnt1 > nums.size() / 3)
        ans.push_back(f);
    if (cnt2 > nums.size() / 3)
        ans.push_back(s);
    return ans;
}
