#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n){
    //code
    map<int,int>mp;
    for(int i=0;i<size;i++){

            int temp = n+arr[i];
            int temp2 = abs(n-arr[i]);
        if(mp.find(temp)!=mp.end() or mp.find(temp2)!=mp.end())
                return true;
                
        mp.insert({arr[i], i});
    }
    return false;
}