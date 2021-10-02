static int findPlatform(int arr[], int dep[], int n){
        int i = 0, j = 0;
        Arrays.sort(arr);
        Arrays.sort(dep);
        int count = 0, ans = 0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            
            ans = Math.max(ans,count);
        }
        return ans;
    }