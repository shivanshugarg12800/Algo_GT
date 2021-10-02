class Solution {
    
    /* Logic Brief
       case1: every node has exactly one parent means indegree of each node should be 1 except root node
       case2: if there is a cycle present then the edge resposnible for the cycle has to return
       case3: if both the above cases gonna occur on same time eg
        [[1,4],[2,1],[3,1],[4,2]] here we have to chose that edge whose indegree is greater than 1 and aslo the part of cycle (thats the tricky part to handle)    
       
    */
    
    int par[];
    public int findPar(int u){
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    }
    public int[] detectCycleByUnionFind(int[][] edges, int[] edge){
        int n = edges.length;
        par = new int[n+1];
        for(int i=1;i<=n;i++){
            par[i] = i;
        }
        
        for(int[] a: edges){
            
            if(a[0] == edge[0] && a[1] == edge[1]) continue;
            
            int gp1 = findPar(a[0]);
            int gp2 = findPar(a[1]);
            if(gp1 != gp2){
                par[gp2] = gp1;
            }
            else{
                return a;
            }
        }
        return null;
    }
    
    
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int indegree[] = new int[n+1];
        int vtxwithTwoPar = -1; 
        for(int[] a: edges){
            if(++indegree[a[1]] == 2) vtxwithTwoPar = a[1];
        }
        
        if(vtxwithTwoPar == -1){
            return detectCycleByUnionFind(edges, new int[]{-1,-1});
        }
        
        for(int i = edges.length -1; i>=0; i--){
            int e[] = edges[i];
            if(e[1] == vtxwithTwoPar){
                int[] a = detectCycleByUnionFind(edges,e);
                if(a == null){
                    return e;
                }
                
            }
        }
        
        return new int[2];
        
        
    }
}