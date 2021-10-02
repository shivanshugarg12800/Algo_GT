 #include <iostream>
#include<unordered_map>
#include<string.h>
#include<math.h>
using namespace std;
 int power ( int n){
    int ans =1;
      for(int i =0; i<n;i++){
          ans = ans * 10;
      }
      return ans;
}

int myAtoi(string str) {
        int num =0;
int n = str.length();
int k = n-1;
 if(str[0]< 48 && str[0]>57){
     return 0;
 }

for(int i=0;i<str.length();i++){
    if(str[i]== ' ')
    {
        break;
        return num;
    }
   int num1 = (str[i] - 48) * power(k);
   num += num1;
   k--;
}
    //  num1 = pow(2, 31);
    //     if(num< - num1){
    //         return -num1;
    //     }
    //     else if(num > num1)
    //     {
    //         return num1;
    //     }
         if(str[0]== '-')
        {
            return -num;
        }
        else{
            return num;
        }
        return 0;
    }
    int main (){
        string str = "23456 hi";
        cout<< myAtoi(str);

    }