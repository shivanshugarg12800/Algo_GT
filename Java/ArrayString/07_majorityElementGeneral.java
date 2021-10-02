 //M1: O(nlogn), O(1)
    public int countOccurence(int[] arr, int n, int k) {
        Arrays.sort(arr);
        int count = 0;
        for(int i=0;i<n;){
            if(i + (n/k) < n && arr[i] == arr[i + (n/k)]) count++;
            i++;
            while(i<n && arr[i] == arr[i-1]) i++; 
        }
        return count;
    }
    //M2: O(n), O(n)
    public int countOccurence(int[] arr, int n, int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        
        for(int ele: arr){
            map.put(ele,map.getOrDefault(ele,0) + 1);
            if(!ans.contains(ele) && map.get(ele) > n/k){
                ans.add(ele);
                
            } 
        }
        return ans.size();
    }