public int[] sortedSquares(int[] nums) {
        //Hint1 you can get max square values on extremes point either on arr[0] or on arr[n-1]
        //Hint2 Last se apna ans ko fill karte jao with maximum value using 2 pointer approach
        int n = nums.length;
        int si = 0, ei = n-1;
        int res[] = new int[n];
        for(int i=n-1;i>=0;i--){
            if(Math.abs(nums[si]) >= Math.abs(nums[ei])){
                res[i] = nums[si] * nums[si];    
                si++;
            }else{
                res[i] = nums[ei] * nums[ei];    
                ei--;
            }
        }
        return res;
    }
    