//M1: Sorting TC-O(nlogn), SC-O(1)
    public int majorityElement(int[] arr) {
        Arrays.sort(arr);
        return arr[arr.length/2];
    }
    //M2: HashMap TC-O(n), SC-O(n)
    public int majorityElement(int[] arr) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int n = arr.length;
        for(int ele:arr){
            map.put(ele, map.getOrDefault(ele,0) + 1);
            if(map.get(ele) > n/2) return ele;
        }
        return -1;
    }
    //M3: Boyer-Moore Voting Algorithm TC-O(n), SC-O(1)
    public int majorityElement(int[] arr) {
        int ans = 0, count = 0;
        for(int ele: arr){
            if(count == 0) ans = ele;
            
            count = count + (ans==ele ? 1 : -1);
        }
        return ans;
    }