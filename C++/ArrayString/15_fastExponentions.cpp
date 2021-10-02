#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll arr[1000001];
ll power(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = (a * a);
        b = b >> 1;
    }
    return res;
}
int main()
{
    ll a, b, c;
    cin >> a >> b;
    ll ans = power(a, b);
    cout << ans << endl;
}