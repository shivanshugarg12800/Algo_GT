#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void SelectionSort()
{
    int a[10];
    int n;
    cout << " Enter number of Elements:    ";
    cin >> n;
    cout << "\n Enter unsorted array:        ";
    for (int i = 0; i < n; i++) //input array
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minIndex = j;
            }
        }
        a[minIndex] = a[i];
        a[i] = min;
    }
    cout << "\n Array after Sort:      ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    clock_t start, finish;
    double cpu_time_used;
    start = clock();
    SelectionSort();
    finish = clock();
    cpu_time_used = ((double)(finish - start)) / CLOCKS_PER_SEC;
    cout << " " << cpu_time_used << "\n";
}