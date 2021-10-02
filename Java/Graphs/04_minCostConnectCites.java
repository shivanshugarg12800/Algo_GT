import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
class graph{
    public static class Edge{
        int v;
        int w;
        Edge(int v,int w){
            this.v = v;
            this.w = w;
        }
    }
    public static void addEdge(ArrayList<Edge>[] graph,int u,int v,int w){
        graph[u].add(new Edge(v,w));
        graph[v].add(new Edge(u,w));
    }

    public static void display(ArrayList<Edge>[] graph, int N){
        for(int i=0;i<N;i++){
            System.out.print(i + " -> ");
            for(Edge e: graph[i]){
                System.out.print("(" + e.v + ", "+ e.w + ") ");
            }
            System.out.println();
        }
    }

    public static class primsPair{
        int vtx;
        int par;
        int wt;
        primsPair(int vtx,int par,int wt){
            this.vtx = vtx;
            this.par = par;
            this.wt = wt;
        }
    }

    public static int minCostConnectCites(int[][] grid){
        int n = grid.length;
        int m = grid[0].length;
        
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[n];
        for(int i=0;i<n;i++) graph[i] = new ArrayList<>();

        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                if(grid[i][j] != 0){
                    addEdge(graph,i,j,grid[i][j]);
                }
            }
        }
        int minCost = 0;
        PriorityQueue<primsPair> pq = new PriorityQueue<>((a,b)->{
            return a.wt - b.wt;
        });
        pq.add(new primsPair(0,-1,0));

        boolean[] vis = new boolean[n];
        int edgeCount = 0;
        
        while(edgeCount < n-1){
            primsPair rp = pq.remove();
            if(vis[rp.vtx]) continue;
            if(rp.par != -1) edgeCount++;
            minCost += rp.wt;
            vis[rp.vtx] = true;
            for(Edge e: graph[rp.vtx]){
                if(!vis[e.v]){
                    pq.add(new primsPair(e.v,rp.vtx,e.w));
                }
            } 
        }
        return minCost;
    }
    public static void main(String[] args){
        int[][] grid = {{0, 1, 1, 100, 0, 0},
         {1, 0, 1, 0, 0, 0},
         {1, 1, 0, 0, 0, 0},
         {100, 0, 0, 0, 2, 2},
         {0, 0, 0, 2, 0, 2},
         {0, 0, 0, 2, 2, 0}};
        System.out.println(minCostConnectCites(grid));                
    }   
}