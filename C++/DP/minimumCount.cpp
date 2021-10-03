// in this we need to find the minimum count of  sum of square of integers for a given integer
// like 10 = 3^2 + 1^2

#include <iostream>
#include <math.h>
using namespace std;
// Recursive Approach..
int minimumCount(int n)
{
    if ((sqrt(n) - floor(sqrt(n))) == 0) // to check if the number is perfect square or not ;
    {
        return 1;
    }

    if (n <= 3)
    {
        return n; // for n=1 we have 1....for n=2 we have (1^2 + 1^2)
    }

    int temp = n; // this is because maximum number of squares are n (1^2 + 1^2 + 1^2 +......)
    for (int i = 1; i <= floor(sqrt(n)); i++)
    {
        int temp2 = i * i;
        if (temp2 > n)
            break;

        else
        {
            temp = min(temp, 1 + minimumCount(n - temp2));
        }
    }
    return temp;
}

// memoisation approach
int minCount_M(int n, int *data)
{
    if ((sqrt(n) - floor(sqrt(n))) == 0) // to check if the number is perfect square or not ;
    {
        return 1;
    }
    if (data[n] != -1) // checking and returning side by side
    {
        return data[n];
    }
    int min = INT32_MAX;
    for (int i = 1; i <= floor(sqrt(n)); i++)
    {
        int temp = i * i;
        int ans = minCount_M(n - temp, data);
        if (ans < min)
            min = ans;
    }
    data[n] = min + 1;

    return min + 1;
}
int main()
{
    int n;
    cin >> n;
    cout << minimumCount(n) << endl;
    int *data = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        data[i] = -1;
    }
    cout << minCount_M(n, data);
}