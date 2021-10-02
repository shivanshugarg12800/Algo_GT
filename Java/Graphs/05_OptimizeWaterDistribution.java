static int[] par;
    public static int findPar(int u){
        if(par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }
    public static int minCostToSupplyWater(int n,int[] wells,int[][] pipes){
        int m = pipes.length;
        ArrayList<int[]> edges = new ArrayList<>();

        for(int[] a: pipes){
            edges.add(a);
        }
        for(int i=0;i<n;i++){
            edges.add(new int[]{0,i+1,wells[i]});
        }
        Collections.sort(edges,(a,b)->{
            return a[2] - b[2];
        });
        int minCost = 0;
        par = new int[n+1];
        for(int i=0;i<=n;i++) par[i] = i;

        for(int i=0;i<edges.size();i++){
            int[] a = edges.get(i);

            int gp1 = findPar(a[0]);
            int gp2 = findPar(a[1]);

            if(gp1 != gp2){
                par[gp2] = gp1;
                minCost += a[2];
            }
        }
        return minCost;
    }

    public static void main(String[] args) {
        int n = 3;
        int[] wells = {1,2,2};
        int[][] pipes = {{1,2,1},{2,3,1}};

        System.out.println(minCostToSupplyWater(n,wells,pipes));
    }