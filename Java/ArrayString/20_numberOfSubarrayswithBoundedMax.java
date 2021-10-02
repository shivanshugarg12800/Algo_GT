public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int n = nums.length, count =0;
        int dp[] = new int[n];
        int si = 0;
        for(int ei=0;ei<n;ei++){ 
            if(nums[ei] < left){
                dp[ei] = (ei-1 < 0) ? 0 : dp[ei-1];
            }
            else if(nums[ei] > right){
                dp[ei] = 0;
                si = ei+1;
            }
            else{
                dp[ei] = ei - si +1;
            }

        }
        
        for(int ele: dp) count+= ele;
        return count;
    }