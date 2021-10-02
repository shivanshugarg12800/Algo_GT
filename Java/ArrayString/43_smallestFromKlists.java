public int[] smallestRange(List<List<Integer>> arr){
        
        int n = arr.size();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->{
            return arr.get(a[0]).get(a[1]) - arr.get(b[0]).get(b[1]);
        });
        int maxVal = -(int)1e9;
        for(int i=0;i<n;i++){
            pq.add(new int[]{i,0});
            maxVal = Math.max(maxVal,arr.get(i).get(0));
        }
        int si = -1,ei = -1,range = (int)1e9;
        
        while(pq.size() == n){
            int[] idx = pq.remove();
            int i = idx[0];
            int j = idx[1];
            int val = arr.get(i).get(j);
            
            if(maxVal - val < range){
                range = maxVal - val;
                si = val;
                ei = maxVal;
            }
            j++;
            if(j < arr.get(i).size()){
                pq.add(new int[]{i,j});
                maxVal = Math.max(maxVal, arr.get(i).get(j));
            }
        }
        
        return new int[]{si,ei};
    }