public void swap(int[] arr,int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public void sortColors(int[] arr){
        int n=arr.length, i=0, j=0, k=0;
        while(k < n){
            if(arr[k]==0){
                swap(arr,j,k++);
                swap(arr,i++,j++); 
            }
            else if(arr[k]==1){
                swap(arr,j++,k++);
            }else{
                k++;
            }
        }
    }