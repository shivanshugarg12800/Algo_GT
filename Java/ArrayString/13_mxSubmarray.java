public int maxSubArray(int[] nums) {
        int gsum = -(int)1e8, csum = 0;
        for(int ele: nums){
            csum += ele;
            if(csum > gsum) gsum = csum;
            if(csum <= 0) csum = 0;
        }
        return gsum;
    }