#include<bits/stdc++.h>
using namespace std;

void deci_to_bin(int x, string & bin_num)
{
    if (x <= 1)
        bin_num += (char)(x + '0');
    else {
       
        deci_to_bin(x / 2, bin_num);
        
        if(x%2)
          bin_num += '1';
       
        else
          bin_num += '0';
    }
}
 
int main()
{
    string bin_num = "";
    int n; 
    cin>>n; 
   
    deci_to_bin(n, bin_num);
     
    cout<<bin_num;
    
    return 0;
}
