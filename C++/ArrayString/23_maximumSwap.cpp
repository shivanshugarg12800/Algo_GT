#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num)
{
    string str = to_string(num);
    int m = INT_MIN;
    int idx = -1;
    int idx1 = -1;
    int idx2 = -1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] - '0' > m)
        {
            m = str[i] - '0';
            idx = i;
            continue;
        }
        if (str[i] - '0' < m)
        {
            idx1 = i;
            idx2 = idx;
        }
    }

    if (idx1 == -1)
        return num;
    swap(str[idx1], str[idx2]);
    return stoi(str);
}