public int twoSumSmaller(int[] arr,int si, int tar) {
        int ans = 0;
        int n = arr.length;
        for(int i=si;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = arr[i] + arr[j];
                if(sum >= tar){
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
    public int threeSumSmaller(int[] arr, int tar) {
        int n = arr.length;
        Arrays.sort(arr);
        int ans = 0;
        for(int i=0;i<n-2;i++){
            ans += twoSumSmaller(arr,i+1,tar-arr[i]);
        }
        return ans;
    }