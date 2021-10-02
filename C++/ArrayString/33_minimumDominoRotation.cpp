#include <bits/stdc++.h>
using namespace std;

int minDominoRotations(vector<int> &tops, vector<int> &btm)
{
    map<int, int> mp;
    int res = -1;
    for (auto it : tops)
        mp[it]++;
    int maxT = 0, countT = 0;
    for (auto it : mp)
    {
        if (it.second > countT)
        {
            countT = it.second;
            maxT = it.first;
        }
    }
    mp.clear();
    for (auto it : btm)
        mp[it]++;
    int maxB = 0, countB = 0;
    for (auto it : mp)
    {
        if (it.second > countB)
        {
            countB = it.second;
            maxB = it.first;
        }
    }
    if (countB > countT)
    {
        int ans = 0, n = btm.size() - countB;
        for (int i = 0; i < btm.size(); i++)
            if (btm[i] != maxB and tops[i] == maxB)
                ans++;
        if (ans == n)
            res = ans;
    }
    else
    {
        int ans = 0, n = tops.size() - countT;
        for (int i = 0; i < tops.size(); i++)
            if (tops[i] != maxT and btm[i] == maxT)
                ans++;
        if (ans == n)
            res = ans;
    }
    return res;
}