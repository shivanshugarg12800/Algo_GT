int mod = (int)1e9 + 7;
    public int twoSumMulti(int[] arr,int si,int ei, int tar) {
        long ans = 0;
        int n = arr.length;
        while(si < ei){
            int sum = arr[si] + arr[ei];
            if(sum < tar) si++;
            else if(sum > tar) ei--;
            else if(arr[si] != arr[ei]){
                int lc = 1, rc = 1;
                si++;ei--;
                while(si <= ei && arr[si] == arr[si-1]){
                    lc++;
                    si++;
                }
                while(si <= ei && arr[ei] == arr[ei + 1]){
                    rc++;
                    ei--;
                }
                ans += lc * rc;
                ans %= mod;
            }
            else{
                int N = ei - si + 1;
                ans += (N * (N-1))/2;
                ans %= mod;
                break;
            }
        }
        return (int)ans;
    }
    public int threeSumMulti(int[] arr, int tar) {
        int n = arr.length;
        Arrays.sort(arr);
        int ans =  0;
        for(int i=0;i<n-2;i++){
            ans = (ans + twoSumMulti(arr,i+1,n-1, tar - arr[i]));
            ans %= mod;
        }
        return ans;
    }