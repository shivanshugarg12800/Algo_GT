public int[] productExceptSelf(int[] arr) {
        int n = arr.length;
        int ans[] = new int[n];
        
        int prefix = 1;
        for(int i=0;i<n;i++){
            ans[i] = prefix;
            prefix *= arr[i];
        }
        int postfix = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] *= postfix;
            postfix *= arr[i];
        }
        return ans;
    }