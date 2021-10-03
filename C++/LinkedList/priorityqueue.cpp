#include <iostream>
#include <queue>

template<typename T> void showpq(T pq){
    T PQ=pq;
    while(!PQ.empty()){
        std::cout<<PQ.top()<<" ";
        PQ.pop();
    }
    std::cout<<"\n";
}

int main(){
    //default c++ creates max heap
    //demonstration for max heap
    std::priority_queue<int> pq;
    pq.push(2);
    pq.push(13);
    pq.push(20);
    pq.push(10);

    std::cout<<"current queue: ";
    showpq(pq);
    std::cout<<"\n pop value: ";
    pq.pop();
    std::cout<<"\n now queue: ";
    showpq(pq);

    std::cout<<"\nmin heap demonstration"<<std::endl;

    std::priority_queue<int,std::vector<int>,std::greater<int>> pq2;
    for(int x:{1,3,5,8,0,9}){
        pq2.push(x);
    }

    std::cout<<"min heap priority queue: ";
    showpq(pq2);

    std::cout<<std::endl;
    std::cout<<"compare elements"<<std::endl;

    auto cmp=[](int left,int right){return (left ^ 1) < (right ^ 1);};
    std::priority_queue<int,std::vector<int>,decltype(cmp)> pq3(cmp);
    for(int x:{1,3,5,2,8,4,7,6,0,9}){
        pq3.push(x);
    }

    showpq(pq3);

    return 0;
}
