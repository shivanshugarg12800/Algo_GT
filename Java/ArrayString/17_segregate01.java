public void binSort(int[] arr) {
        int sum = 0;
        int n = arr.length;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (sum == 0)
            {
                A[i] = 0;
                continue;
            }
            else
                A[i] = 1;
            sum--;
        }
    }