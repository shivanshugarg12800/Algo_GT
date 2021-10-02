//!!Caution: There is mistake is main function in line no 29 there shoub be K but on GFG N is there!!

//Initial Template for Java


/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;


class graph {
    
    // Driver code
    
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
	    Complete obj = new Complete();
		// looping through all testcases
		while(testcases-- > 0){
		    String line = br.readLine();
		    String[] element = line.trim().split("\\s+");
		    int N = Integer.parseInt(element[0]);
		    int K = Integer.parseInt(element[1]);
		    int arr [][] = new int[N][2];
		    for(int i = 0;i<K;i++){
	            line = br.readLine();
		        String[] elements = line.trim().split("\\s+");
		        arr[i][0] = Integer.parseInt(elements[0]);
		        arr[i][1] = Integer.parseInt(elements[1]);    
	        }
            int ans = obj.doctorStrange(N, K, arr);
            System.out.println(ans);
    	    
		}
	}
}



// } Driver Code Ends


//User function Template for Java

//User function Template for Java


class Complete{
    
    // Function for finding maximum and value pair
    static int[] low,disc;
    static boolean[] vis,isAP;
    static int time = 0, rootCalls = 0;
    
    public static void dfsAP(ArrayList<Integer>[] graph,int src,int par){
        low[src] = disc[src] = time++;
        vis[src] = true;
        for(int nbr: graph[src]){
            if(!vis[nbr]){
                if(par == -1) rootCalls++;
                dfsAP(graph,nbr,src);
                if(disc[src] <= low[nbr]) isAP[src] = true;
                low[src] = Math.min(low[src],low[nbr]);
            }
            else if(nbr != par){
                low[src] = Math.min(low[src], disc[nbr]);
            }
        }
    }
    
    public static int doctorStrange (int n, int k, int bridges[][]) {
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        for(int i=0;i<=n;i++) graph[i] = new ArrayList<>();
        
        for(int[] a: bridges){
            graph[a[0]].add(a[1]);
            graph[a[1]].add(a[0]);
        }
        
        low = new int[n+1];
        disc = new int[n+1];
        vis = new boolean[n+1];
        isAP = new boolean[n+1];
        
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfsAP(graph,i,-1);
                
                if(rootCalls == 1) isAP[i] = false;
                rootCalls = 0;
            }
        }
        int ans = 0;
        for(boolean ele: isAP){
            if(ele) ans++;
        }
        return ans;
        
    }
    
    
}