import java.util.*;

public class StrassenMult
{
    /** Function to multiply matrices **/
    public int[][] StrassenMultiply(int[][] a, int[][] b)
    {        
        int n = a.length;
        
        int[][] ans = new int[n][n];
        
        
        if (n == 1)
            ans[0][0] = a[0][0] * b[0][0];
        
        
            else
        {
            int[][] a11 = new int[n/2][n/2];
            int[][] a12 = new int[n/2][n/2];
            int[][] a21 = new int[n/2][n/2];
            int[][] a22 = new int[n/2][n/2];
            int[][] b11 = new int[n/2][n/2];
            int[][] b12 = new int[n/2][n/2];
            int[][] b21 = new int[n/2][n/2];
            int[][] b22 = new int[n/2][n/2];
 
            
            breakMatrix(a, a11, 0 , 0);
            breakMatrix(a, a12, 0 , n/2);
            breakMatrix(a, a21, n/2, 0);
            breakMatrix(a, a22, n/2, n/2);


            breakMatrix(b, b11, 0 , 0);
            breakMatrix(b, b12, 0 , n/2);
            breakMatrix(b, b21, n/2, 0);
            breakMatrix(b, b22, n/2, n/2);
 
            /** 
              M1 = (a11 + a22)(b11 + b22)
              M2 = (a21 + a22) b11
              M3 = a11 (b12 - b22)
              M4 = a22 (b21 - b11)
              M5 = (a11 + a12) b22
              M6 = (a21 - a11) (b11 + b12)
              M7 = (a12 - a22) (b21 + b22)
            **/
 
            int [][] M1 = StrassenMultiply(add(a11, a22), add(b11, b22));
            int [][] M2 = StrassenMultiply(add(a21, a22), b11);
            int [][] M3 = StrassenMultiply(a11, sub(b12, b22));
            int [][] M4 = StrassenMultiply(a22, sub(b21, b11));
            int [][] M5 = StrassenMultiply(add(a11, a12), b22);
            int [][] M6 = StrassenMultiply(sub(a21, a11), add(b11, b12));
            int [][] M7 = StrassenMultiply(sub(a12, a22), add(b21, b22));
 
            /**
              C11 = M1 + M4 - M5 + M7
              C12 = M3 + M5
              C21 = M2 + M4
              C22 = M1 - M2 + M3 + M6
            **/

            int [][] C11 = add(sub(add(M1, M4), M5), M7);
            int [][] C12 = add(M3, M5);
            int [][] C21 = add(M2, M4);
            int [][] C22 = add(sub(add(M1, M3), M2), M6);
 
            
            join(C11, ans, 0 , 0);
            join(C12, ans, 0 , n/2);
            join(C21, ans, n/2, 0);
            join(C22, ans, n/2, n/2);
        }  
        return ans;
    }



    public int[][] sub(int[][] a, int[][] b)
    {
        int n = a.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = a[i][j] - b[i][j];
        return C;
    }
    

    public int[][] add(int[][] a, int[][] b)
    {
        int n = a.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = a[i][j] + b[i][j];
        return C;
    }
    


    public void breakMatrix(int[][] parent, int[][] child, int row_start, int col_start) 
    {
        for(int i1 = 0, i2 = row_start; i1 < child.length; i1++, i2++)
            for(int j1 = 0, j2 = col_start; j1 < child.length; j1++, j2++)
                child[i1][j1] = parent[i2][j2];
    }


    public void join(int[][] child, int[][] parent, int row_start, int col_start) 
    {
        for(int i1 = 0, i2 = row_start; i1 < child.length; i1++, i2++)
            for(int j1 = 0, j2 = col_start; j1 < child.length; j1++, j2++)
                parent[i2][j2] = child[i1][j1];
    }    
    


    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        StrassenMult s = new StrassenMult();
 
        System.out.println("Enter k of Matrix :");
        
        int k = sc.nextInt();

        int N = (int)(Math.pow(2.00, (double)k));
        
        
        int[][] a = new int[N][N];
        
        Random rand = new Random();
        int min = 0;
        int max = 30;
        int upperBound = max - min + 1;
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = min+rand.nextInt(upperBound);
 
        int[][] b = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                b[i][j] = min+ rand.nextInt(upperBound);

        System.out.println("\nMatrix A:\n");        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }

        System.out.println("\nMatrix B:\n");        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                System.out.print(b[i][j]+" ");
            }
            System.out.println();
        }

        
    

        long start = System.nanoTime();

        int[][] C = s.StrassenMultiply(a, b);

        long end = System.nanoTime();
        long execution = end - start;
        System.out.println("\n\nExecution time: " + execution + " nanoseconds\n\n");

 
        System.out.println("\nAnswer of Multiplication : ");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                System.out.print(C[i][j] +" ");
            System.out.println();
        }
 
    }
}