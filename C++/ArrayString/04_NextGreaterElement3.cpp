#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n)
{
    string s = to_string(n);
    long long int num;
    int len = s.size();
    int i, j;
    for (i = len - 2; i >= 0; i--)
    {
        if ((s[i] - '0') < (s[i + 1] - '0'))
            break;
    }
    if (i < 0)
        return -1;
    else
    {
        int j = len - 1;
        for (; j >= 0; j--)
        {
            if ((s[j] - '0') > (s[i] - '0'))
                break;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        num = stoll(s);
        if (num > INT_MAX)
            return -1;
    }
    return num;
}