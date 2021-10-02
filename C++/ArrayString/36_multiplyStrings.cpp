#include <bits/stdc++.h>
using namespace std;
string multiply(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    string res(m + n, '0');
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int a = s1[i] - '0';
            int b = s2[j] - '0';
            int c = (res[i + j + 1] - '0') + a * b;
            res[i + j + 1] = c % 10 + '0';
            res[i + j] += c / 10;
        }
    }
    for (int i = 0; i < res.length(); i++)
        if (res[i] != '0')
            return res.substr(i);
    return "0";
}