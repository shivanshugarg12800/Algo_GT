//Its a naive approach but a correct one! and gives TLE if you submit it on codechef editor 
public static class Edge{
        int v;
        int w;
        Edge(int v,int w){
            this.v = v;
            this.w = w;
        }
    }
    
    public static void addEdge(ArrayList<Edge>[] graph,int u,int v){
        graph[u].add(new Edge(v,0));
        graph[v].add(new Edge(u,1));
    }
    static int minWeight = (int)1e9;
    public static void minWeightPath(ArrayList<Edge>[] graph,int src,int dest,int wt,boolean[] vis){
        if(src==dest){
            minWeight = Math.min(minWeight,wt);
            return;
        }
        vis[src] = true;
        for(Edge e: graph[src]){
            if(!vis[e.v]){
                minWeightPath(graph,e.v,dest,wt + e.w,vis);
            }
        }
        vis[src] = false;
        
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
	    BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
	    String num[] = inp.readLine().split(" ");
	    int N = Integer.parseInt(num[0]);
	    int M = Integer.parseInt(num[1]);
		ArrayList<Edge>[] graph = new ArrayList[N+1];
		for(int i=0;i<=N;i++){
		    graph[i] = new ArrayList<>();
		}
		for(int i=0;i<M;i++){
		    String st[] = inp.readLine().split(" ");
		    int u = Integer.parseInt(st[0]);
		    int v = Integer.parseInt(st[1]);
		    addEdge(graph,u,v);
		}
		boolean vis[] = new boolean[N+1];
		minWeightPath(graph,1,N,0,vis);
		if(minWeight == (int)1e9) System.out.println("-1");
		else System.out.println(minWeight);
		
	}