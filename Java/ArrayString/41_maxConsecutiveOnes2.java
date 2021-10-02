public int findMaxConsecutiveOnes(int[] nums) {
        int si =0, ei = 0, n = nums.length,len = -1, count =0 ;

        while(ei < n){
            if(nums[ei++] == 0) count++;
            while(count > 1){
                if(nums[si++] == 0) count--;
            }
            len = Math.max(len,ei - si);
        }
        return len;
    }