int mod = (int)1e9 +7;
    public long kadanesAlgo(int[] arr,int k){
        int n=arr.length;
        long gsum = 0, csum =0;
        for(int i=0;i<n*k;i++){
            int ele = arr[i%n];
            csum += ele;
            if(csum > gsum) gsum = csum;
            if(csum <= 0) csum = 0;
        }
        return gsum % mod;
    }
    public int kConcatenationMaxSum(int[] arr, int k) {
        long prevSum = 0;
        for(int i=1;i<=3;i++){
            long kadaneSum = kadanesAlgo(arr,i);
            if(i==k){
                return (int)kadaneSum;
            }
            if(i==3) return (int)(prevSum + ((k-2)*(kadaneSum - prevSum)) % mod);
            prevSum = kadaneSum;
        }
        return 0;
    }