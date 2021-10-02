#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &mat)
{
    int i = 0, j = mat.size() - 1, n = mat.size();
    while (i < j)
    {
        swap(mat[i], mat[j]);
        i++, j--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                swap(mat[i][j], mat[j][i]);
        }
    }
}