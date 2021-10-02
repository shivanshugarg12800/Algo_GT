public int getIntersect(ArrayList<Integer> list){
        int i = 0, j = list.size()-1, res = 0;
        while(i<j){
            res += list.get(j--) - list.get(i++);
        }
        return res;
    } 
    public int minTotalDistance(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        ArrayList<Integer> xPoints = new ArrayList<>();
        ArrayList<Integer> yPoints = new ArrayList<>();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    xPoints.add(i);
                    yPoints.add(j);
                }
            }
        }
        Collections.sort(yPoints);
        return getIntersect(xPoints) + getIntersect(yPoints);
    }
