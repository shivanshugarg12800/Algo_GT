// in this question we need to find the number of primes between a given range of n and m
// n and m can be very large upto 1o^8 but (m-n<=10^6)
// so we'll make a array of size m-n+1 and then mark all the multiples of the primes in this range only
// for any number i and n, if we want to get the nearest multiple of i then ((n/i)*i)

#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;
vector<int> primes; // to store the prime numbers

int p[N] = {0}; // to mark the numbers prime or not

void sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (p[i] == 0)
        {
            // store i in the primes
            primes.push_back(i);
            // mark all the multples of i as not prime
            for (int j = i * i; j <= N; j += i)
            {
                p[j] = 1;
            }
        }
    }
}
int main()
{
    sieve(); // build sieve once for all the queries
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        bool segment[n - m + 1] = {0}; // array of numbers b/w n and m

        // segmented sieve logic
        for (auto x : primes)
        {
            // for terminating the loop
            if (x * x > n)
            {
                break;
            }

            // to start the loop with the nearest multiple of the x
            int start = (m / x) * x;

            if (x >= m and x <= n)
            {
                start = 2 * x;
            }
            for (int i = start; i <= n; i += x)
            {
                segment[i - m] = 1;
            }
        }
        // loop over range m..n to print primes
        for (int i = m; i <= n; i++)
        {
            if (segment[i - m] == 0 and i != 1)
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }
}