// Calculate value of a number raised to power n

#include<iostream>
using namespace std;

int power(int x, int n){

    if(n==0){
        return 1;
    }

    return x * power(x, n-1);

}

// Calculating power of a number in logarithmic time complexity
int power_in_logarithmic_time (int x, int n){

    if(n==0) return 1;

    int x_power_n_by_2 = power_in_logarithmic_time(x, n/2); // x^n = x^(n/2) * x^(n/2); and we apply this logic on every recursive call
    int x_power_n = x_power_n_by_2 * x_power_n_by_2;

    // for odd n, eg;, 1023, n/2 = 511 and so x^1023 = x^511 * x^511 * x;
    // so we need to multiply x_power_n by x to get the value of x^n in case of odd n

    // by this logic we need to call this function recursively for logn times. foreg, for n=1024, this function is called recursively for 512, 256, 128, 64, 32, 16, 8, 4, 2, 1, i.e. only ten times which is logbase2 to 1024

    if(n%2==1) x_power_n *= x;

    return x_power_n;


}

int main(){

    int n = power_in_logarithmic_time(2, 20);
    cout<<n;
    return 0;
}
