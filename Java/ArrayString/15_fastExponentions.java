static int[] numOfSubsets(int[] arr , int n) {
        int mod = (int)1e9 + 7; 
        int minVal = (int)1e9,minCount= 0;
        for(int ele: arr){
            if(ele < minVal){
                minVal = ele;
                minCount=0;
            }
            if(minVal == ele){
                minCount++;
            }
        }
        int maxVal = -(int)1e9,maxCount= 0;
        for(int ele: arr){
            if(ele > maxVal){
                maxVal = ele;
                maxCount=0;
            }
            if(maxVal == ele){
                maxCount++;
            }
        }
        int max = (int)(Math.pow(2,maxCount) - 1) % mod;
        int min = (int)(Math.pow(2,minCount) - 1) % mod;
        return new int[]{max,min};
    }