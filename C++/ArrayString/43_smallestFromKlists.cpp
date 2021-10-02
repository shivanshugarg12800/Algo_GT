#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    vector<pair<int, int>> mp;
    int i = 1;
    for (auto it : nums)
    {
        for (auto x : it)
            mp.push_back({x, i});

        i++;
    }
    sort(mp.begin(), mp.end());
    for (auto it : mp)
        cout << it.first << "-> " << it.second << endl;
    int n = nums.size();
    int total = 0;
    vector<int> count(n + 1, 0);
    i = 0;
    int si = 0, ei = 0, j = 0, maxLen = INT_MAX;
    while (i < mp.size())
    {
        // cout<<mp[i].first<<" ";
        count[mp[i].second]++;
        if (count[mp[i].second] == 1)
        {
            total++;
        }
        if (total == n)
        {
            int len = mp[i].first - mp[j].first;
            // cout<<"len : "<<len<<endl;
            if (len < maxLen)
            {
                maxLen = len;
                si = mp[j].first;
                ei = mp[i].first;
            }
        }
        if (total == n)
        {
            while (total == n)
            {
                if (count[mp[j].second] > 1)
                {
                    count[mp[j].second]--;
                    j++;
                }
                else
                    break;
            }
            int len = mp[i].first - mp[j].first;
            if (len < maxLen)
            {
                maxLen = len;
                si = mp[j].first;
                ei = mp[i].first;
            }
        }
        i++;
    }
    // cout<<maxLen<<endl;
    return {si, ei};
}