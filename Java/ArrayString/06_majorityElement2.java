//M1:
    public List<Integer> majorityElement(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<n;){
            if( i + (n/3) < n && arr[i] == arr[i + (n/3)]) ans.add(arr[i]);
            i++;
            while(i<n && arr[i] == arr[i-1]) i++; 
        }
        return ans;
    }
    //M2:
    public List<Integer> majorityElement(int[] arr) {
        List<Integer> ans = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        int n = arr.length;
        for(int ele: arr){
            map.put(ele,map.getOrDefault(ele,0) + 1);
            if(!ans.contains(ele) && map.get(ele) > n/3) ans.add(ele);
        }
        return ans;
    }
    //M3:
    public List<Integer> majorityElement(int[] arr) {
        List<Integer> ans = new ArrayList<>();
        int n = arr.length;
        if(n == 1){
            ans.add(arr[0]);
            return ans;
        }
        
        int num1 = arr[0];
        int num2 = arr[1];
        int count1 = 0;
        int count2 = 0;
        for(int ele: arr){
            if(num1 == ele){
                count1++;
            }
            else if(num2 == ele){
                count2++;
            }
            else if(count1 == 0){
                num1 = ele;
                count1++;
            }
            else if(count2 == 0){
                num2 = ele;
                count2++;
            }
            else{
                count1--;
                count2--;
            }    
        }
        
        count1 = 0;
        count2 = 0;
        
        for(int ele: arr){
            if(ele == num1) count1++;
            else if(ele == num2) count2++;
        }
        if(count1 > n/3) ans.add(num1);
        if(count2 > n/3) ans.add(num2);
        
        return ans;
    }