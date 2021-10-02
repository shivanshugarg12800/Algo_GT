public void swap(int[][] matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        
        for(int gap = 1;gap < n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                swap(matrix,i,j);
            }
        }
        
        for(int i=0;i<n;i++){
            int si = 0, ei = m-1;
            while(si < ei){
                int temp = matrix[i][si];
                matrix[i][si] = matrix[i][ei];
                matrix[i][ei] = temp;
                si++;ei--;
            }
        }
    }