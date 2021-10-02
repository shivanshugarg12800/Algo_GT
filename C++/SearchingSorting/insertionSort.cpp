#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void InsertionSort()
{
    int a[100];
    int n;
    cout << " Enter number of Elements:    ";
    cin >> n;
    cout << "\n Enter unsorted array:        ";
    for (int i = 0; i < n; i++) //input array
    {
        cin >> a[i];
    }
    int curr = 0;
    int i, j;
    for (i = 1; i < n; i++)
    {
        curr = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > curr)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
    cout << "\n Array after Insertion Sort:  ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    clock_t start, finish;
    double cpu_time_used;
    start = clock();
    InsertionSort();
    finish = clock();
    cpu_time_used = ((double)(finish - start)) / CLOCKS_PER_SEC;
    cout << " " << cpu_time_used << "\n";
}
