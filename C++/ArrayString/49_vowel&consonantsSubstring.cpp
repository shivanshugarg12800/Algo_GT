// Vowel and Consonant Substrings!
// Given a string A consisting of lowercase characters.
// You have to find the number of substrings in A which 
// starts with vowel and end with consonants or vice-versa.
// Return the count of substring modulo 1e9 + 7.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool isVowel(char ch){
        return(ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u' );
    }
    int solve(string A){
        int n=A.size();
        long long int vow=0,cons=0;
        int mod= 1000000007;
        for(int i=0;i<n;i++){
            if(isVowel(A[i])){
                vow=(vow+1)%mod;
            }
            else{
                cons=(cons+1)%mod;
            }
        }
        // Product of number of vowels and consonants in a string is the
        // count of special strings
        long long int count=(vow*cons)%mod;
        return mod;
    }
    int solveMethod2(string A){
        int n=A.size();
        if(n==1 || n==0){
            return 0;
        }
        int mod=1000000007;
        long long int vow=0,cons=0;
        for(int i=0;i<n;i++){
            vow+=isVowel(A[i]);
        }
        vow=vow%mod;
        cons=n-vow;
        cons=cons%mod;
        // We will first calculate number of vowels and consonants
        long long int count=0;
        for(int i=0;i<n;i++){
            if(isVowel(A[i])){
                // if the string is abcdef
                // it has 2 vowels and 4 consonants
                // observe that after we determine that a is the vowel
                // the special string must end with consonant
                // it could be ab, abc, abcd, abcdef which is
                // equal to number of consonants left ahead in the string
                vow=(vow-1)%mod;
                count+=cons;
            }
            else{
                cons=(cons-1)%mod;
                count+=vow;
            }
            // the mod function is to match the interviewbit criteria
            count=count%mod;
        }
        return (int)count;
    }
};