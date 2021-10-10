package Java.mathematics;

import java.util.*;

public class sieveOfEratosthenes {
    public static void main(String [] args) {
        int n=35;
        boolean isPrime[]=new boolean[n+1];
        Arrays.fill(isPrime,true);
        soe(n, isPrime);
        
        System.out.println("isPrime?");
        for(int i=0;i<n+1;i++) {
            System.out.println(i+"->"+isPrime[i]);
        }
    }
    private static void soe(int n, boolean [] isPrime) {
        isPrime[0]=isPrime[1]=false;

        for(int i=2;i<=n*n;i++) {
            for(int j=2*i;j<=n;j+=i) {
                isPrime[j]=false;
            }
        }
    }
}
