import java.util.ArrayList;
class ArticulationPointandBridges{
    static int N = 7;
    @SuppressWarnings("unchecked")
    static ArrayList<Integer>[] graph = new ArrayList[N];

    public static void addEdge(int u, int v){
        graph[u].add(v);
        graph[v].add(u);
    }

    static int[] low = new int[N];
    static int[] disc = new int[N];
    static boolean[] vis = new boolean[N];
    static boolean[] isAP = new boolean[N];
    static int time=0,rootCalls = 0;
    
    public static void dfsAP(int src,int par){
        low[src] = disc[src] = time++;
        vis[src] = true;
        for(int nbr: graph[src]){
            if(!vis[nbr]){
                if(par == -1) rootCalls++;
                dfsAP(nbr,src);
                if(disc[src] <= low[nbr]) isAP[src] = true;
                low[src] = Math.min(low[src],low[nbr]);
            }
            else if(nbr != par){
                low[src] = Math.min(low[src], disc[nbr]);
            }
        }
    }

    public static void ArticulationPoint(){

        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfsAP(i,-1);

                if(rootCalls == 1) isAP[i] = false;
                rootCalls = 0;
            }
        }

        for(int i=0;i<N;i++){
            if(isAP[i]) System.out.print(i + " ");
        }
    }

    public static void main(String[] args){
      for(int i=0;i<N;i++) graph[i] = new ArrayList<>();
      addEdge(0,1);
      addEdge(1,2);
      addEdge(2,0);
      addEdge(1,3);
      addEdge(1,4);
      addEdge(1,6);
      addEdge(3,5);
      addEdge(4,5);

      ArticulationPoint();
    }
}