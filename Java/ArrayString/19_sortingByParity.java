public void swap(int[] arr,int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public int[] sortArrayByParity(int[] arr) {
        int n = arr.length, i=0,j = 0;
        
        while(j<n){
            if(arr[j] % 2 == 0){
                swap(arr,i++,j++);
            }
            else j++;
        }
        return arr;
    }