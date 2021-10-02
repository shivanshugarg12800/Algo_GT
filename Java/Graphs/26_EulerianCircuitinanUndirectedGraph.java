class Solution
{
    public boolean isEularCircuitExist(int N, ArrayList<ArrayList<Integer>> edges)
    {
        int degree[] = new int[N];
        for(int i=0;i<N;i++){
            for(int j:edges.get(i)){
                degree[j]++;
            }
        }
        int count = 0;
        for(int ele: degree){
            if(ele%2 != 0) count++;
        }
        return (count == 0) ? true : false;
    }
}