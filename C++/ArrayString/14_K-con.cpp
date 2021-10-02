#include <bits/stdc++.h>
using namespace std;

pair<long, long> maxsubindex(long *arr, long size)
{
    long max_so_far = arr[0];
    long current_max = 0;
    int index = 0;
    for (long i = 0; i < size; i++)
    {
        current_max = current_max + arr[i];
        if (max_so_far < current_max)
        {
            max_so_far = current_max;
            index = i;
        }
        if (current_max < 0)
        {
            current_max = 0;
        }
    }
    return make_pair(index, max_so_far);
}

int main()
{
    long t;
    cin >> t;
    long n, k;

    for (long i = 0; i < t; i++)
    {
        cin >> n >> k;
        long arr[2 * n];
        long count_neg = 0;
        long sum = 0;
        for (long j = 0; j < n; j++)
        {
            cin >> arr[j];
            arr[n + j] = arr[j];
            sum = sum + arr[j];
            if (arr[j] < 0)
            {
                count_neg++;
            }
        }

        pair<long, long> temp = maxsubindex(arr, 2 * n);
        long max_sub_sum = temp.second;
        long max_sub_index = temp.first;

        if (k < 2)
        {
            cout << maxsubindex(arr, n).second << endl;
            continue;
        }
        if (count_neg == 0)
        {
            cout << sum * k << endl;
            continue;
        }
        else if (count_neg == n)
        {
            sort(arr, arr + n);
            cout << arr[n - 1] << endl;
            continue;
        }
        else if (sum > 0)
        {
            if (max_sub_sum > sum * 2)
            {
                if (max_sub_index < n)
                {
                    cout << max_sub_sum + ((k - 1) * sum) << endl;
                }
                else
                {
                    cout << max_sub_sum + ((k - 2) * sum) << endl;
                }
            }
            else
                cout << sum * k << endl;
            continue;
        }
        else if (sum <= 0)
        {
            cout << max_sub_sum << endl;
            continue;
        }
    }
}
