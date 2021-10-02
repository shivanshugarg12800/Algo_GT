#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]] = i;
    }
    vector<int> ans;
    int ptr = 0, j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int last = mp.find(s[i])->second;
        j = max(j, last);
        if (i == j)
        {
            ans.push_back(i - ptr + 1);
            ptr = i + 1;
        }
    }

    return ans;
}