import java.util.ArrayList;
import java.util.Arrays;
class kruskalAlgo{

    static int[] par;
    static int[] size;

    public static int getPar(int u){
        if(par[u] == u) return u;
        return par[u] = getPar(par[u]);
    }

    public static void merge(int gp1,int gp2){
        if(size[gp1] >= size[gp2]){
            par[gp2] = gp1;
            size[gp1] += size[gp2];
        }else{
            par[gp1] = gp2;
            size[gp2] += size[gp1];
        }
    }

    public static int kruskalAlgo(int[][] edges,int N){
        ArrayList<int[]> ans = new ArrayList<>();
        par = new int[N];
        size = new int[N];

        for(int i=0;i<N;i++){
            par[i] = i;
            size[i] = 1;
        }
        int minCost = 0;
        for(int[] a: edges){
            int gp1 = getPar(a[0]);
            int gp2 = getPar(a[1]);
            if(gp1 != gp2){
                merge(gp1,gp2);
                minCost += a[2];
                ans.add(a);
            }
        }
        for(int[] a: ans){
            System.out.println(a[0] + "--" + a[1] + " = " + a[2]);
        }
        return minCost;
    }

    public static void main(String[] args){
        int[][] edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
        int N = 4;

        Arrays.sort(edges,(a,b)->{
            return a[2] - b[2];
        });

        System.out.println(kruskalAlgo(edges,N));
    }

}