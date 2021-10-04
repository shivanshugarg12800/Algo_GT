public int rodCut(int[] price, int n)
    {
        // `T[i]` stores the maximum profit achieved from a rod of length `i`
        int[] T = new int[n + 1];
 
        // consider a rod of length `i`
        for (int i = 1; i <= n; i++)
        {
            // divide the rod of length `i` into two rods of length `j`
            // and `i-j` each and take maximum
            for (int j = 1; j <= i; j++) {
                T[i] = Integer.max(T[i], price[j - 1] + T[i - j]);
            }
        }
 
        // `T[n]` stores the maximum profit achieved from a rod of length `n`
        return T[n];
    }