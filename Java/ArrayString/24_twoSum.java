boolean hasArrayTwoCandidates(int arr[], int n, int x) {
        Arrays.sort(arr);
        int i = 0, j = n-1;
        
        while(i<j){
            int sum = arr[i] + arr[j];
            
            if(sum == x){
                return true;
            }
            else if(sum > x){
                j--;    
            }
            else{
                i++;
            }
        }
        
        return false;
    }
