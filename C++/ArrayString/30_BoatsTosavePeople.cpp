#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int n = people.size();
    int si = 0, ei = n - 1;
    int count = 0;
    while (si < ei)
    {
        if (people[si] + people[ei] > limit)
            ei--;
        else
        {
            si++, ei--;
        }
        count++;
    }
    if (si == ei)
        count++;

    return count;
}