public int numBusesToDestination(int[][] routes, int src, int dest) {
        if(src == dest) return 0;
        int n = routes.length;
        HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();
        for(int busNo = 0;busNo <n;busNo++){
            for(int busStand: routes[busNo]){
                if(!map.containsKey(busStand)){
                    map.put(busStand, new ArrayList<>());
                }
                map.get(busStand).add(busNo);
            }
        }
        
        boolean[] busNoVis = new boolean[n];
        HashSet<Integer> busStandVis = new HashSet<>();
        
        Queue<Integer> que = new LinkedList<>();
        que.add(src);
        busStandVis.add(src);
        int level = 0;
        while(que.size() != 0){
            int size = que.size();
            while(size-->0){
                int stand = que.remove();
            
                for(int busNo: map.get(stand)){
                    if(busNoVis[busNo]) continue;
                    busNoVis[busNo] = true;
                    for(int busStand: routes[busNo]){
                        if(busStandVis.contains(busStand)) continue;
                        busStandVis.add(busStand);

                        que.add(busStand);
                        if(busStand == dest) return level+1;
                    }
                }
            }
            level++;
        }
        return -1;
    }