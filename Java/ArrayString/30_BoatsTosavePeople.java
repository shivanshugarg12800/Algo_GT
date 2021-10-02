public int numRescueBoats(int[] arr, int limit) {
        Arrays.sort(arr);
        int n = arr.length, si = 0, ei = n-1;
        int usedBoat =0;
        while(si < ei){
            int wt = arr[si] + arr[ei];
            if(wt <= limit) si++;
            ei--;
            usedBoat++;
            
        }
        if(si==ei) usedBoat++;
        return usedBoat;
    }