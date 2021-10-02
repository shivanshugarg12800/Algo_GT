public int maxChunksToSorted(int[] arr) {
        int count = 0,maxEle = 0, n= arr.length;
        for(int i=0;i<n;i++){
            maxEle = Math.max(maxEle,arr[i]);
            if(maxEle == i) count++;
        }
        return count;
    }