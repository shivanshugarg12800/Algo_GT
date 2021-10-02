#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int n = s.size();
    if (n <= 2)
        return true;
    int i = 0, j = n - 1;
    int d = 1;
    while (i < j)
    {
        if (s[i] != s[j] and d == 1)
        {
            return isValid(s, i, j - 1) or isValid(s, i + 1, j);
            d -= 1;
        }
        else if (s[i] != s[j] and d == 0)
            return false;
        else
            i++, j--;
    }
    return true;
}