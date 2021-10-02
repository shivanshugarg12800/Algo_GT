// in this we will be using the hashmaps to implement the code which says we need to remove the duplicates in
// the array..
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


vector <int> removeDuplicate(int* a, int size)
{
    vector<int> output;
    unordered_map<int, bool> ourMap;
    for(int i=0; i<size; i++){
      if(ourMap.count(a[i])>0)
      continue;
      ourMap[a[i]]=true;
      output.push_back(a[i]);
    }
    return output;
}
int main()
{
    int a[]={1,2,2,3,5,6,4,2,7,3,4,4,5};
    int size=13;
    vector<int> output= removeDuplicate(a, size);
    for(int i=0; i<output.size(); i++)
    {
        cout<< output[i]<<" ";
    }
}