public boolean findPair(int arr[], int n, int tar)
    {
        if(n == 1) return false;
        Arrays.sort(arr);
        int i = 0, j = 1;
        
        while(i<n && j<n){
            int diff = arr[j] - arr[i];
            
            if(i != j && diff == tar){
                return true;
            }
            else if(diff < tar){
                j++;    
            }
            else{
                i++;
            }
        }
        return false;
    }