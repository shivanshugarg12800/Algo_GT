#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s)
{
    int r = s.size() - 1;
    int l = 0;
    while (l < r)
    {
        bool isVowelL = (tolower(s[l]) == 'a') || (tolower(s[l]) == 'e') || (tolower(s[l]) == 'i') || (tolower(s[l]) == 'o') || (tolower(s[l]) == 'u');
        bool isVowelR = (tolower(s[r]) == 'a') || (tolower(s[r]) == 'e') || (tolower(s[r]) == 'i') || (tolower(s[r]) == 'o') || (tolower(s[r]) == 'u');
        if (isVowelL && isVowelR)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
        if (!isVowelL)
            l++;
        if (!isVowelR)
            r--;
    }
    return s;
}