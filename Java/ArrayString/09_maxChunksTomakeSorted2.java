public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int prefixMax[] = new int[n];
        int suffixMin[] = new int[n];
        
        prefixMax[0] = arr[0];
        suffixMin[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            prefixMax[i] = Math.max(prefixMax[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffixMin[i] = Math.min(suffixMin[i+1],arr[i]);
        }
        
        int count = 1;
        for(int i=0;i<n-1;i++){
            if(prefixMax[i] <= suffixMin[i+1]) count++;
        }
        return count;
    }