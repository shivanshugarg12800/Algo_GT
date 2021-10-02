public int twoSumClosest(int[] arr,int si,int ei,int tar){
        int ans = (int)1e9;
        while(si < ei){
            int sum = arr[si] + arr[ei];
            if(sum == tar){
                return tar;
            }
            else if(sum < tar){
                if(tar - sum < ((ans > tar)?ans-tar:tar-ans) ) ans = sum;
                si++;
            }
            else{
                if(sum - tar < ((ans > tar)?ans-tar:tar-ans)  ) ans = sum;
                ei--;
            }
        }
        return ans;
    }
    public int threeSumClosest(int[] arr, int tar) {
        Arrays.sort(arr);
        int ans = (int)1e9;
        int n =arr.length;
        for(int i=0;i<n-2;i++){
            int smallAns = twoSumClosest(arr,i+1,n-1,tar - arr[i]);            
            smallAns = smallAns + arr[i];
            if(smallAns == tar) return tar;
            else if(smallAns < tar){
                ans = (tar - smallAns < ((ans > tar)?ans-tar:tar-ans)  ) ? smallAns : ans;
            }
            else{
                ans = (smallAns - tar < ((ans > tar)?ans-tar:tar-ans)  ) ? smallAns : ans;
            }
        }
        return ans;
    }