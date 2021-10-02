#include <bits/stdc++.h>
using namespace std;

int threeSumMulti(vector<int> &arr, int target)
{
    // sort(nums.begin(), nums.end());
    map<int, int> mp;
    sort(arr.begin(), arr.end());
    for (auto &i : arr)
        mp[i]++;
    int n = arr.size();
    vector<vector<int>> res;
    for (int k = 0; k < n; k++)
    {
        if (k > 0 && arr[k] == arr[k - 1])
            continue; // avoid duplicate as earlier we would have calculated every possibility of nums[k];
        int i = k + 1, j = n - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == target)
            {
                res.push_back({arr[k], arr[i], arr[j]});
                while (i < j && arr[i] == arr[i + 1])
                    i++;
                while (i < j && arr[j] == arr[j - 1])
                    j--;
                i++;
                j--;
            }
            else if (sum > target)
                j--;
            else
                i++;
        }
    }
    long ans = 0;
    for (auto &v : res)
    {
        if (v[0] == v[1] && v[1] == v[2])
        {
            //nc3
            long x = mp[v[0]];
            ans += x * (x - 1) * (x - 2) / 6;
        }
        else if (v[0] == v[1])
        {
            long x = mp[v[0]];
            ans += (x * (x - 1) / 2) * mp[v[2]];
        }
        else if (v[1] == v[2])
        {
            long x = mp[v[1]];
            ans += (x * (x - 1) / 2) * mp[v[0]];
        }
        else
            ans += mp[v[0]] * mp[v[1]] * mp[v[2]];
    }
    return ans % 1000000007;
}