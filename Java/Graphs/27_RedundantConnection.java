class Solution {
    int par[];
    public int findPar(int u){
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int ans[] = new int[2];
        par = new int[n+1];
        for(int i=1;i<=n;i++){
            par[i] = i;
        }
        
        for(int[] a: edges){
            int gp1 = findPar(a[0]);
            int gp2 = findPar(a[1]);
            if(gp1 != gp2){
                par[gp2] = gp1;
            }
            else{
                ans[0] = a[0];
                ans[1] = a[1];
                break;
            }
        }
        return ans;
    }
}