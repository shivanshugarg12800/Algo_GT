public int minDominoRotations(int[] tops, int[] bottoms) {
        int[] count = new int[7];
        int num1 = 0, count1 = 0;
        int num2 = 0, count2 = 0;
        for(int ele: tops){
            count[ele]++;
            if(count1 < count[ele]){
                count1 = count[ele];
                num1 = ele;
            }
        }
        count = new int[7];
        for(int ele: bottoms){
            count[ele]++;
            if(count2 < count[ele]){
                count2 = count[ele];
                num2 = ele;
            }
        }
        int num = (count1 >= count2) ? num1 : num2 ;
        int n = tops.length;
        for(int i=0;i<n;i++){
            if(tops[i] != num && bottoms[i] != num) return -1;
        }
        return (count1 >= count2) ? n-count1 : n-count2;
    }