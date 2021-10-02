public List<List<Integer>> twoSum(int[] arr,int si,int ei,int tar){
        List<List<Integer>> res = new ArrayList<>();
        while(si < ei){
            int sum = arr[si] + arr[ei];
            if(sum == tar){
                List<Integer> ans = new ArrayList<>();
                ans.add(arr[si]);
                ans.add(arr[ei]);
                res.add(ans);
                si++;
                ei--;
                while(si < ei && arr[si] == arr[si-1]) si++;
                while(si < ei && arr[ei] == arr[ei+1]) ei--;
            }
            else if(sum < tar) si++; 
            else ei--;
        }
        return res;
    }
    public void prepareAns(List<List<Integer>> smallAns,int ele, List<List<Integer>> res){
        for(List<Integer> a: smallAns){
            List<Integer> ans = new ArrayList<>();
            ans.add(ele);    
            for(int e: a) ans.add(e);
            res.add(ans);
        }
    }
    public List<List<Integer>> threeSum(int[] arr,int si, int ei,int tar){
        List<List<Integer>> res = new ArrayList<>();
        for(int i=si;i<ei;){
            List<List<Integer>> smallAns = twoSum(arr,i+1,ei,tar - arr[i]);
            prepareAns(smallAns,arr[i],res);
            i++;
            while(i<ei && arr[i] == arr[i-1]) i++; //Mistake udplicate no. ke liye nahi chalana hai
        }
        return res;
    }
    
    public List<List<Integer>> threeSum(int[] nums){
        int n = nums.length;
        Arrays.sort(nums);
        return threeSum(nums,0,n-1,0);
    }