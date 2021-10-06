import java.io.*;


class QuickSort{

    public static void sort(int a[], int left, int right){

        if (right > left)
        {
            int i=left, j=right, tmp;    
            int pivot = a[right]; 
     
            do {
                while(a[i]<pivot)
                i++;
                while(a[j]>pivot)
                j--;
     
                if( i <= j){            
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    i++;            
                    j--;
          
                }
            } while(i <= j);   
            if(left < j)
            sort(a,left,j);
 
      
          if(i < right)
            sort(a,i,right);
         }
     }
     
     public static void printArray(int a[],int n){
     for(int i=0;i<n;i++)
         {
                 System.out.print(a[i]+" ");
         }
     System.out.println(""); }
     public static void main(String[] args) throws IOException{

        InputStreamReader isr= new InputStreamReader(System.in);
        BufferedReader br= new BufferedReader(isr);
        int n;
        
        System.out.println("Enter the size of the array");
        String st= br.readLine();
        n=Integer.parseInt(st);
        int a[]=new int[n];
        
        System.out.println("Enter Elements :");
        
        for(int i=0;i<n;i++)
        {
          a[i]=Integer.parseInt(st);
        }
        
        sort(a,0,n-1);
        System.out.println("Array Sorted :");
        printArray(a,n);
    }
}
 