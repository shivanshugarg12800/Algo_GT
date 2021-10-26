#include <iostream>
using namespace std;
#include<climits>


int findMinVertex(int* weight , int n , bool* visited){
  int min_vertex = -1;
  for(int i=0;i<n;i++){
    if(!visited[i] && (min_vertex==-1 || weight[i]<weight[min_vertex])){
      min_vertex = i;
    }
  }
  return min_vertex;
}



void dijkistra(int** graph , int n){
   
   // step1
  bool* visited = new bool[n];
  int* weight = new int[n];
  
  for(int i=0;i<n;i++){
    visited[i] = false;
    weight[i] = INT_MAX;
  }

  // step2
  // we are taking node 0 as source
  weight[0] = 0;
  
  for(int i=0;i<n-1;i++){
    
      // step3
    int min_vertex = findMinVertex(weight , n , visited);
    visited[min_vertex] = true;
    
    // step4
    for(int j=0;j<n;j++){
       if(!visited[j] && graph[min_vertex][j] && weight[j] > (graph[min_vertex][j] + weight[min_vertex])){
        weight[j] = graph[min_vertex][j] + weight[min_vertex];
      }
    }

    
  }


for(int i=1 ; i<n ; i++){
  cout<<"Distance b/w src and "<<i<<" is "<<weight[i]<<endl;
}


}




int main()
{

    // graph
  int n , e;
  cin >> n >> e;
  int** graph = new int*[n];
  for(int i=0;i<n;i++){
    graph[i] = new int[n];
    for(int j=0;j<n;j++){
      graph[i][j] = 0;
    }
  }
  
  for(int i=0;i<e;i++){
    int s,d,w;
    cin>>s>>d>>w;
    graph[s][d] = w;
    graph[d][s] = w;
  }
  
  
  dijkistra(graph , n);
  
  return 0;
}


