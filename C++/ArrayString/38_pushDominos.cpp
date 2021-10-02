#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string domino)
{
    // we traverse the string, consider the force applied by Right push is sufficient to push the next N dominos, and the force of impact keeps on decreasing with dominos

    int force = 0;
    int n = domino.size();
    vector<int> forces(n, 0);
    // we first traverse the string for all the right push and make all the left push to be zero
    for (int i = 0; i < n; i++)
    {
        if (domino[i] == 'R')
            force = n;
        else if (domino[i] == 'L')
            force = 0;
        else
            force = max(force - 1, 0);

        forces[i] += force;
    }
    // we first traverse the string for all the right push and make all the left push to be zero
    for (int i = n - 1; i >= 0; i--)
    {
        if (domino[i] == 'L')
            force = n;
        else if (domino[i] == 'R')
            force = 0;
        else
            force = max(force - 1, 0);

        forces[i] -= force;
    }
    string ans = "";
    for (auto it : forces)
    {
        if (it > 0)
            ans += 'R';
        else if (it < 0)
            ans += 'L';
        else
            ans += '.';
    }
    return ans;
}