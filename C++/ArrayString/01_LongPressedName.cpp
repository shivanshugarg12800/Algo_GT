#include <bits/stdc++.h>
using namespace std;

bool isLongPressedName(string name, string typed)
{
    int i = 0, j = 0;
    if (typed.size() < name.size())
        return false;

    while (i < name.size() || j < typed.size())
    {
        // this is for the condition when characters are same
        //  we increment the i and j
        if (i < name.size() and j < typed.size() and name[i] == typed[j])
        {
            i++;
            j++;
        }
        // if not equal then there is possibility that typed[j] can be equal to i-1
        else if (i > 0 and j < typed.size() and name[i - 1] == typed[j])
        {
            j++;
        }
        else
            return false;
    }
    //cout << i << " " << j << endl;
    //         if(i<name.size()) return false;
    //         if(j<typed.size()){

    //         }
    return true;
}