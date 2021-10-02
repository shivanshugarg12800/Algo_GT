// in this we need to find the largest common subsequence of given two strings

#include<iostream>
#include<string.h>
using namespace std;
// Recursive or Brute force approach...
int LCS_rec(string s, string t)
{
    if(s.size()==0 || t.size()==0)
    {
       return 0;
    }
    if(s[0]==t[0])
    {
        return 1+LCS_rec(s.substr(1), t.substr(1));
    }
    // if our first character does not  matches we get three cases 
    // calling the first string leaving the first character 
    // calling the second string leaving the first character
    // calling both the strings leaving the first character 

    int x=LCS_rec(s.substr(1), t);
    int y=LCS_rec(s, t.substr(1));
    int z=LCS_rec(s.substr(1), t.substr(1));

    return max(x,max(y,z));

}
int LCS_mem_helper(string s, string t, int **data)
{
     int m= s.size();
     int n= t.size();
    
     if(s.size()==0 || t.size()==0)
    {
       return 0;
    }
    // check if the answer exists
    if(data[m][n]!=-1)
    {
        return data[m][n];
    }
    if(s[0]==t[0])
    {
        return 1+LCS_rec(s.substr(1), t.substr(1));
    }
    int x=LCS_mem_helper(s.substr(1), t, data);
    int y=LCS_mem_helper(s, t.substr(1), data);
    int z=LCS_mem_helper(s.substr(1), t.substr(1), data);
    // save the answer for future use
    data[m][n]= max(x, max(y,z));

    return data[m][n];
}
 int LCS_mem(string s,string t)
 {
     int m= s.size();
    int n= t.size();
    int **data= new int*[m+1];
    for(int i=0; i<=m;i++)
    {
        data[i] = new int[n+1];
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0; j<=n;j++)
        {
            data[i][j]=-1;
        }
    }
    return LCS_mem_helper(s, t, data);
 }
 // Dynamic programing approach..
int LCS_DP(string s, string t)
{
     
int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = 0;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			// Check if 1st char matches
			if(s[m-i] == t[n-j]) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
			}
		}
	}

	return output[m][n];
}
int main()
{
    string s,t;
    cin>> s>> t;
    cout<< LCS_rec(s, t)<<endl;
    cout<< LCS_mem(s, t)<<endl;
    cout<<LCS_DP(s, t);
}