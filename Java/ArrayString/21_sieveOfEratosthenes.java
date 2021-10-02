static ArrayList<Integer> sieveOfEratosthenes(int N){
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[] primes = new boolean[N+1];
        Arrays.fill(primes,true);
        primes[0] = primes[1] = false;
        for(int i=2;i<=N;i++){
            if(primes[i]){
                for(int p=i*i;p<=N;p+=i) primes[p] = false;
            }
        }
        
        for(int i=0;i<=N;i++){
            if(primes[i]) ans.add(i);
        }
        return ans;
    }