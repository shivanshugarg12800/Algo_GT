#include <bits/stdc++.h>
using namespace std;

void BubbleSort()
{
    int A[100];
    int n;
    cout << " Enter number of Elements: ";
    cin >> n;
    int temp;
    cout << "\n Enter unsorted array:     ";
    for (int i = 0; i < n; i++) //to input array
    {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    cout << "\n Array after Bubble Sort:  ";
    for (int i = 0; i < n; i++) //to output array
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    clock_t start, finish;
    double cpu_time_used;
    start = clock();
    BubbleSort();
    finish = clock();
    cpu_time_used = ((double)(finish - start)) / CLOCKS_PER_SEC;
    cout << " " << cpu_time_used << "\n";
}