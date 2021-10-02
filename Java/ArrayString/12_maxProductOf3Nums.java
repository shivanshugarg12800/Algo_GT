//M1: O(nlogn)
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return Math.max( (nums[0]*nums[1]*nums[n-1]) , (nums[n-1]*nums[n-2]*nums[n-3]));
    } 
    //M2: O(n)
    public int maximumProduct(int[] nums) {
        int max1 = -(int)1e8, max2 = -(int)1e8, max3 = -(int)1e8; 
        int min1 = (int)1e8, min2 = (int)1e8;
        
        for(int ele: nums){
            if(ele > max1){
                max3 = max2;
                max2 = max1;
                max1 = ele;
            }
            else{
                if(ele > max2){
                    max3 = max2;
                    max2 = ele;
                }
                else{
                    max3 = Math.max(max3,ele);
                }
            }
            if(ele > min1){
                min2 = Math.min(min2,ele);
            }
            else{
                min2 = min1;
                min1 = ele;
            }
        }
        return Math.max((max1*max2*max3), (min1*min2*max1));
    }