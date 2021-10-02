#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> v;
    long long int prev = 1;
    v.push_back(prev);

    for (int i = 1; i <= rowIndex; i++)
    {
        long long int curr = (prev * (rowIndex - i + 1)) / i;
        v.push_back(curr);
        prev = curr;
    }
    //v.push_back(1);
    return v;
}