//Main thing to remember here is one of the extreme points must included in our ans
    //Case 1: nums[0] is -ve and nums[n-1] is +ve ans will include nums[n-1]
    //Case 2: nums[0] is +ve and nums[n-1] is -ve ans will include nums[0]
    //Case 3: nums[0] is +ve and nums[n-1] is +ve both will be included
    //Case 4: nums[0] is -ve and nums[n-1] is -ve
        //Case 4.1 product of [nums[1],nums[n-2]] is +ve then both will included
        //Case 4.2 product of [nums[1],nums[n-2]] is -ve  then ans will be Math.max([nums[0],nums[n-2]],[nums[1],nums[n-1]])
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int ans = nums[0];
        int l = 0, r = 0;
        for(int i=0;i<n;i++){
            l = (l==0 ? 1 : l) * nums[i];
            r = (r==0 ? 1 : r) * nums[n-1-i];
            ans = Math.max(ans,Math.max(l,r));
        }
        return ans;
    }